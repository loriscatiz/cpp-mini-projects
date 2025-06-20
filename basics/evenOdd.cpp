#include <iostream>
#include <vector>

bool isOdd(int num);
bool isEven(int num);
int evenSum(std::vector<int> nums);
int oddSum(std::vector<int> nums);
void printNumList(std::vector<int> nums);

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {1, 3, 5, 2, 455, 1, 89, 4, 5};
    int evenSumVal = evenSum(nums);
    int oddSumVal = oddSum(nums);

    std::cout << "Hello, here is the input provided\n\n";
    printNumList(nums);

    std::cout << "The sum of the odd numbers is: " << oddSumVal << "\n";
    std::cout << "The sum of the even numbers is: " << evenSumVal << "\n";

    return 0;
}

bool isOdd(int num)
{
    return !isEven(num);
}

bool isEven(int num)
{
    return num % 2 == 0;
}

int evenSum(std::vector<int> nums)
{
    int total = 0;
    for (int num : nums)
    {
        if (isEven(num))
            total += num;
    }

    return total;
}

int oddSum(std::vector<int> nums)
{
    int total = 0;
    for (int num : nums)
    {
        if (isOdd(num))
            total += num;
    }

    return total;
}

void printNumList(std::vector<int> nums)
{
    for (int num : nums)
    {
        std::cout << num << std::endl;
    }
}
