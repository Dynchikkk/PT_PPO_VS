//#include <iostream>
#include <windows.h>
#include "loadTime.h"

typedef void (*RunTimeFunc)();

int main(int argc, char* argv[])
{
	HMODULE hLib = LoadLibrary(TEXT("runTimeLib.dll"));
	if (!hLib) {
		//std::cout << "Failed to load runtime library. Error: " << GetLastError() << std::endl;
		return 1;
	}
	RunTimeFunc runTimeFunc = (RunTimeFunc)GetProcAddress(hLib, "RunTimeFunc");
	if (!runTimeFunc) {
		//std::cout << "Failed to get RunTimeFunc function address. Error: " << GetLastError() << std::endl;
		FreeLibrary(hLib);
		return 1;
	}

	runTimeFunc();
	LoadTimeFunc();

	FreeLibrary(hLib);
	return 0;
}