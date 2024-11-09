#include <iostream>
#include <stdexcept>
#include <windows.h>
#include "loadTime.h"

typedef int (*FindElementFunc)(int*, int, int);
typedef void (*GenerateExceptionFunc)();

int main() {
#pragma region LOAD_TIME_DLL
    int result = OpenDocument("test.txt");
    if (result != 0) {
        std::cerr << "Failed to open document" << std::endl;
    }

    result = CloseDocument();
    if (result != 0) {
        std::cerr << "Failed to close document" << std::endl;
    }

    result = GenerateException();
    if (result != 0) {
        std::cerr << "Exception in Load-time DLL" << std::endl;
    }
#pragma endregion

#pragma region RUN_TIME_DLL
    HMODULE hModule = LoadLibrary(TEXT("runTimeLib.dll"));
    if (!hModule) {
        throw std::runtime_error("Failed to load runTimeLib.dll");
    }

    FindElementFunc findElement = (FindElementFunc)GetProcAddress(hModule, "FindElement");
    if (!findElement) {
        throw std::runtime_error("Failed to find FindElement in runTimeLib.dll");
    }

    GenerateExceptionFunc generateException = (GenerateExceptionFunc)GetProcAddress(hModule, "GenerateException");
    if (!generateException) {
        throw std::runtime_error("Failed to find GenerateException in runTimeLib.dll");
    }

    try {
        int table[] = { 1, 2, 3, 4, 5 };
        int index = findElement(table, 5, 3);
        std::cout << "Element found at index: " << index << std::endl;

        generateException();
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception in Run-time DLL: " << ex.what() << std::endl;
    }

    if (hModule) {
        FreeLibrary(hModule);
        hModule = nullptr;
    }
#pragma endregion
    return 0;
}
