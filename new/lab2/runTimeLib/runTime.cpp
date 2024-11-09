#include "runTime.h"
#include <iostream>
#include <stdexcept>

int FindElement(int* table, int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (table[i] == element) {
            return i;
        }
    }
    throw std::runtime_error("Element not found in table");
}

void GenerateException() {
    throw std::runtime_error("Generated exception in Run-time DLL");
}
