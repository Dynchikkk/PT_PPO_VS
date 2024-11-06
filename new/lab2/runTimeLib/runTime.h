#ifndef RUNTIME_H
#define RUNTIME_H

#ifdef RUNTIME_EXPORTS
#define RUNTIME_API __declspec(dllexport)
#else
#define RUNTIME_API __declspec(dllimport)
#endif

RUNTIME_API void RunTimeFunc();
#endif