#include <iostream>

int main(int argc, char const* argv[]) {
    // Step 1: Create two integer variables
    int first = 10;
    int second = 20;

    // Step 2: Create pointers to these variables
    // (You fill this in)
    int* p1 = &first;
    int* p2 = &second;

    // Step 3: Print the values using both the variables and the pointers
    // (You fill this in)
    std::cout << "=== PRINTING USING VARIABLES ===\n\n";

    std::cout << "first: " << first << '\n';
    std::cout << "second: " << second << '\n';

    std::cout << "=== PRINTING USING POINTERS ===\n\n";

    std::cout << "first: (*p1) " << *p1 << '\n';
    std::cout << "second: (*p2) " << *p2 << '\n';

    // Step 4: Use the pointers to swap the values
    // (You fill this in)
    int temp = *p1;
    *p1 = second;
    *p2 = temp;

    std::cout << "=== SWAPPED USING POINTERS ===\n\n";

    // Step 5: Print the values again to confirm the swap worked
    std::cout << "=== PRINTING USING VARIABLES ===\n\n";

    std::cout << "first: " << first << '\n';
    std::cout << "second: " << second << '\n';

    std::cout << "=== PRINTING USING POINTERS ===\n\n";

    std::cout << "first: (*p1) " << *p1 << '\n';
    std::cout << "second: (*p2) " << *p2 << '\n';

    return 0;
}
