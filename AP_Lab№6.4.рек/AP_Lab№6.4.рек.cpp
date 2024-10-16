#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

void generateArray(int a[], int size, int index = 0) {
    if (index == size) return;
    a[index] = rand() % 46 - 10;
    generateArray(a, size, index + 1);
}

void printArray(const int a[], int size, int index = 0) {
    if (index == size) {
        std::cout << std::endl;
        return;
    }
    std::cout << std::setw(5) << a[index];
    printArray(a, size, index + 1);
}

int findMaxIndex(const int a[], int size, int currentMax = 0, int currentIndex = 1) {
    if (currentIndex == size) return currentMax;
    if (a[currentIndex] > a[currentMax]) {
        currentMax = currentIndex;
    }
    return findMaxIndex(a, size, currentMax, currentIndex + 1);
}

int productBetweenZeros(const int a[], int size, int start = 0, int product = 1, bool foundFirst = false) {
    if (start == size) return foundFirst ? 0 : product;
    if (a[start] == 0) {
        if (!foundFirst) {
            return productBetweenZeros(a, size, start + 1, 1, true);
        }
        else {
            return product;
        }
    }
    if (foundFirst) {
        product *= a[start];
    }
    return productBetweenZeros(a, size, start + 1, product, foundFirst);
}

void printTransformedArrayHelper(const int a[], int size, int index, bool isEven) {
    if (index >= size) {
        if (isEven) {
            printTransformedArrayHelper(a, size, 1, false);
        }
        else {
            std::cout << std::endl;
        }
        return;
    }
    std::cout << std::setw(5) << a[index];
    printTransformedArrayHelper(a, size, index + 2, isEven);
}

void printTransformedArray(const int a[], int size) {
    printTransformedArrayHelper(a, size, 0, true);
}

int main() {
    srand((unsigned)time(NULL));

    int size;
    std::cout << "size = ";
    std::cin >> size;

    int* arr = new int[size];

    generateArray(arr, size);

    printArray(arr, size);

    int maxIndex = findMaxIndex(arr, size);
    std::cout << "Max element index: " << maxIndex << std::endl;

    int product = productBetweenZeros(arr, size);
    std::cout << "Product of elements between 0 and 0: " << product << std::endl;

    printTransformedArray(arr, size);

    return 0;
}