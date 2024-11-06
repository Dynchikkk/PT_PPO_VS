#ifndef LOADTIME_H
#define LOADTIME_H

#ifdef LOADTIME_EXPORTS
#define LOADTIME_API __declspec(dllexport)
#else
#define LOADTIME_API __declspec(dllimport)
#endif

LOADTIME_API void LoadTimeFunc();
#endif