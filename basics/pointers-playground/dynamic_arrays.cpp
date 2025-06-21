#include <iostream>

int main() {
    int size;
    std::cout << "How many numbers do you want to store? ";
    std::cin >> size;

    int* arrayPtr = new int[size];

    for (size_t i = 0; i < size; i++) {
        std::cout << "Insert number " << i + 1 << '/' << size << '\n';
        int next;
        std::cin >> next;
        arrayPtr[i] = next;
    }

    std::cout << "=== PRINTING ALL THE NUMBERS ===\n\n";
    for (size_t i = 0; i < size; i++) {
        std::cout << *(arrayPtr + i) << '\n';
    }

    std::cout << "=== FINDING THE MAX AND THE MIN ===\n\n";
    int* pMin = (arrayPtr);
    int* pMax = (arrayPtr);

    for (size_t i = 1; i < size; i++) {
        int* currentPointer = (arrayPtr + i);
        if (*currentPointer < *pMin) {
            pMin = currentPointer;
        }
        if (*currentPointer > *pMax) {
            pMax = currentPointer;
        }
    }

    std::cout << "MAX: " << *pMax << '\n';
    std::cout << "MIN: " << *pMin << '\n';

    delete[] arrayPtr;

    return 0;
}