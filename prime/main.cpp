#include <iostream>
#include <vector>

#include "prime.hpp"

void print_nums(std::vector<int>& nums);

int main(int argc, char const* argv[]) {
    std::vector nums = {1, 2, 3, 4, 5, 6, 7, 8, 17, 9, 10};

    std::cout << "The nums are: ";
    print_nums(nums);

    std::cout << "The largest prime number is: " << largest_prime_num(nums) << '\n';

    for (int num : nums) {
        std::cout << is_perfect_square(num);
    }

    return 0;
}

void print_nums(std::vector<int>& nums) {
    for (size_t i = 0; i < nums.size(); i++) {
        std::cout << nums[i];
        if (i != nums.size() - 1) {
            std::cout << ',';
        } else {
            std::cout << '\n';
        }
    }
}