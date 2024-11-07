#ifndef LOADTIME_H
#define LOADTIME_H

#ifdef BUILD_DLL
    #define LOAD_TIME_EXPORT __declspec(dllexport)
#else
    #define LOAD_TIME_EXPORT __declspec(dllimport)
#endif

extern "C" {
    LOAD_TIME_EXPORT int OpenDocument(const char* filename);
    LOAD_TIME_EXPORT int CloseDocument();
    LOAD_TIME_EXPORT int GenerateException();
}

#endif // LOADTIME_H
