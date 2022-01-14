#include <future>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>
#include <stdexcept>
#include <cstring>
#include "networking.hpp"
#include "throw.hpp"
#include "consts.hpp"
#include "RandomUtil.hpp"

void handleClient(const int& client, const std::vector<std::string>& words)
{
    std::vector<char> buf(1024);
    int n{0};
    while ((n = recv(client, buf.data(), buf.size(), 0)) != 0)
    {
        std::cerr << "server: read " << n << " bytes from client" << std::endl;

        const std::string& randomWord{words[RandomUtil::Next(0, words.size())]};

        // echo data back to client
        throw_if_min1(send(client, randomWord.c_str(), randomWord.length(), 0));
    }
    std::cerr << "server: connection closed by client" << std::endl;
    throw_if_min1(closesocket(client));
}

int main()
{
    try
    {
        std::ifstream wordsStream{"resources/nl.words.txt"};
        std::string wordLine;
        std::vector<std::string> words;
        while (std::getline(wordsStream, wordLine))
        {
            words.emplace_back(wordLine + '\n');
        }

        std::cout << "Words: " << words.size() << std::endl;

        // create stream socket
        int server{0};
        throw_if_min1(server = socket(AF_INET, SOCK_STREAM, 0));

        // fill in address struct for server address
        struct sockaddr_in sa;
        std::memset(&sa, 0, sizeof(struct sockaddr_in));
        sa.sin_family = AF_INET;
        sa.sin_port = htons(ServerPort);
        throw_if_min1(inet_pton(AF_INET, "localhost", &sa.sin_addr.s_addr));

        // bind server to this address
        throw_if_min1(bind(server, reinterpret_cast<struct sockaddr*>(&sa), sizeof(sa)));

        // make server socket passive
        throw_if_min1(listen(server, SOMAXCONN));

        while (true)
        {
            // setup client address struct so we can show it
            int client{0};
            struct sockaddr_storage client_storage;
            socklen_t len{sizeof(struct sockaddr_storage)};
            struct sockaddr* client_endpoint = reinterpret_cast<struct sockaddr*>(&client_storage);

            // wait for a client to connect
            std::cerr << "server: waiting for client\n";
            throw_if_min1(client = accept(server, client_endpoint, &len));

            // translate client address to human readable form
            const struct sockaddr_in* addr = reinterpret_cast<const struct sockaddr_in*>(client_endpoint);
            std::vector<char> cbuf(INET_ADDRSTRLEN);
            inet_ntop(AF_INET, &addr->sin_addr, cbuf.data(), cbuf.size());

            // show client address
            std::cerr << "server: got connection from " << cbuf.data() << ":" << ntohs(addr->sin_port) << std::endl;

            // read data from client
            std::async(std::launch::async, &handleClient, client, words).wait();
        }
        throw_if_min1(closesocket(server));

    }
    catch (const std::exception& ex)
    {
        std::cerr << "server: " << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}