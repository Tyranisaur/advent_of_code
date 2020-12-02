#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
    std::ifstream input = std::ifstream{"input.txt", std::ios_base::in};
    std::unordered_set<int> numbers{};
    constexpr int targetSum = 2020;

    std::cout << "Part 1\n";

    for (std::string line; std::getline(input, line);) {
        const int value = std::stoi(line);
        const int partner = targetSum - value;
        if (numbers.contains(partner)) {
            std::cout << value * partner << '\n';
        }
        numbers.emplace(value);
    }

    std::cout << "Part 2\n";

    const std::vector vec(numbers.begin(), numbers.end());
    auto it = std::array{vec.begin(), vec.begin() + 1, vec.begin() + 2};

    while (it.back() != vec.end()) {
        const int sum = *it[0] + *it[1] + *it[2];
        if (sum == targetSum) {
            std::cout << *it[0] * *it[1] * *it[2] << '\n';
        }
        for (auto iter = it.rbegin(); iter != it.rend(); ++iter) {
            ++*iter;
            if (*iter != vec.end() - (iter - it.rbegin())) {
                for (auto rest = iter.base(); rest != it.end(); ++rest) {
                    *rest = rest[-1] + 1;
                }
                break;
            }
        }
    }
    std::cout << "";
}
