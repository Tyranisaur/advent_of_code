#include <array>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <numeric>
#include <string>
#include <vector>

struct Slope
{
    std::size_t xStep = 0;
    std::size_t yStep = 0;
};

int treesRunningSlope(const std::vector<std::string> &map, const Slope slope)
{
    const auto width = map.front().size();
    int trees = 0;
    std::size_t x = 0;
    std::size_t y = 0;
    while (y < map.size()) {
        const char spot = map[y][x % width];
        if (spot == '#') {
            ++trees;
        }
        y += slope.yStep;
        x += slope.xStep;
    }
    return trees;
}

int main()
{
    std::ifstream input = std::ifstream{"input.txt", std::ios_base::in};
    std::vector<std::string> map;
    std::cout << "Part 1\n";
    for (std::string line; std::getline(input, line);) {
        map.emplace_back(std::move(line));
    }

    const int trees = treesRunningSlope(map, Slope{3, 1});

    std::cout << trees << '\n';

    std::cout << "Part 2\n";

    constexpr std::array slopesToTry{
      Slope{1, 1},
      Slope{3, 1},
      Slope{5, 1},
      Slope{7, 1},
      Slope{1, 2}};

    std::cout << std::transform_reduce(
      slopesToTry.begin(), slopesToTry.end(), std::size_t{1}, std::multiplies<>(), [&map](const Slope slope) { return treesRunningSlope(map, slope); });


    std::cout << "";
}
