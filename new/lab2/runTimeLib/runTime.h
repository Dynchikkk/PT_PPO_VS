#ifndef RUNTIME_H
#define RUNTIME_H

#ifdef BUILD_DLL
    #define RUNTIME_EXPORT __declspec(dllexport)
#else
    #define RUNTIME_EXPORT __declspec(dllimport)
#endif

extern "C" {
    RUNTIME_EXPORT int FindElement(int* table, int size, int element);
    RUNTIME_EXPORT void GenerateException();
}

#endif // RUNTIME_H
