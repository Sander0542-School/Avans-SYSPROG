#include "lib/split-join.hpp"
#include "lib/vector_helpers.hpp"

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main()
{
    std::ifstream t("resources/Alice_in_Wonderland.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();

    auto lines = sp::split(buffer.str(), "\n");
    lines = vh::pick_random(lines, 10);

    std::map<std::string, int> wordCounts{};
    std::regex pat{R"([^[:alpha:]]+)"};

    for (const auto& line: lines)
    {
        auto lineWords = sp::split(line, pat);
        for (const auto& lineWord: lineWords)
        {
            if (!wordCounts.contains(lineWord))
                wordCounts.emplace(lineWord, 0);

            wordCounts[lineWord]++;
        }
    }

    for (const auto& wordPair: wordCounts)
    {
        std::cout << wordPair.first << ": (" << wordPair.second << ") " << std::string(wordPair.second, '*') << std::endl;
    }
}
