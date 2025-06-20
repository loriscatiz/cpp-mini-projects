#include <iostream>
#include <vector>

#include "prime.hpp"

void print_nums(std::vector<int>& nums);

int main(int argc, char const* argv[]) {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 17, 9, 10};

    std::cout << "The nums are: ";
    print_nums(nums);

    std::vector<int> prime_nums;
    std::vector<int> perfect_squares;

    for (int num : nums) {
        if (is_prime(num)) {
            prime_nums.push_back(num);
        }
        if (is_perfect_square(num)) {
            perfect_squares.push_back(num);
        }
    }

    std::cout << "The prime numbers are: \n";
    print_nums(prime_nums);

    std::cout << "The perfect squares are: \n";
    print_nums(perfect_squares);

    std::cout << "The largest prime number is: " << largest_prime_num(prime_nums) << '\n';
    std::cout << "The largest perfect square is: " << largest_perfect_square(perfect_squares)
              << '\n';

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