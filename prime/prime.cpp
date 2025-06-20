#include "prime.hpp"

#include <vector>

bool is_prime(int num) {
    if (num < 2) {
        return false;
    }

    if (num == 2) {
        return true;
    }

    if (num % 2 == 0) {
        return false;
    }

    for (int dividend = 3; dividend <= num / 2; dividend += 2) {
        if (num % dividend == 0) {
            return false;
        }
    }

    return true;
}

bool is_perfect_square(int num) {
    if (num < 0) {
        return false;
    }

    if (num == 0 || num == 1) {
        return true;
    }

    for (int i = 2; i * i <= num; i++) {
        if (i * i == num) {
            return true;
        }
    }
    return false;
}

int largest_prime_num(std::vector<int>& nums) {
    int retval = -1;
    for (int& num : nums) {
        if (num > retval) {
            if (is_prime(num)) {
                retval = num;
            }
        }
    }
    return retval;
}
