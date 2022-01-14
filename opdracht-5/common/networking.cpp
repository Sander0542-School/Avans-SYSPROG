#include "networking.hpp"

#if defined(WIN32) || defined(WIN64)

#include <iostream>

WSA WSA::instance;

WSA::WSA() {
    int iResult = WSAStartup(MAKEWORD(2, 2), &data);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed with error: " << iResult << '\n';
    }
}

WSA::~WSA() {
    WSACleanup();
}

#else // POSIX

int closesocket(int sock) {
    return close(sock);
}

#endif
