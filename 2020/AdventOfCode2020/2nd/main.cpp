#include <iostream>
#include <fstream>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>

bool isValidPasswordPart1(const int min, const int max, const char letter, const std::string_view password)
{
    int occurances = 0;
    for (const auto c : password) {
        if (c == letter) {
            ++occurances;
        }
    }
    return occurances >= min and occurances <= max;
}

bool isValidPasswordPart2(const std::size_t firstIndex, const std::size_t secondIndex, const char letter, const std::string_view password)
{
    return (password[firstIndex - 1] == letter) != (password[secondIndex - 1] == letter);
}

std::vector<std::string> split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main()
{
    std::ifstream input = std::ifstream{"input.txt", std::ios_base::in};

    std::cout << "Part 1\n";

    int validPasswordsPart1 = 0;
    int validPasswordsPart2 = 0;
    for (std::string line; std::getline(input, line);) {
        const auto parts = split(line, ' ');
        const auto limits = split(parts.front(), '-');
        const int firstNumber = std::stoi(limits.front());
        const int secondNumber = std::stoi(limits.back());
        const char letter = parts[1].front();
        const auto &password = parts.back();

        if (isValidPasswordPart1(firstNumber, secondNumber, letter, password)) {
            ++validPasswordsPart1;
        }

        if (isValidPasswordPart2(std::size_t(firstNumber), std::size_t(secondNumber), letter, password)) {
            ++validPasswordsPart2;
        }
    }
    std::cout << validPasswordsPart1 << '\n';

    std::cout << "Part 2\n";
    std::cout << validPasswordsPart2 << '\n';


    std::cout << "";
}
