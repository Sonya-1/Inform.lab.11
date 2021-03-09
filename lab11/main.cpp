#include <stdio.h>
#include "pathsplit.h"

int main() {
	char str[256] = R"(C:\\Users\USER\source\repos\lab9\lab9\main.cpp)";
	char* split[255] = { NULL };

	pathsplit(str, split);

	return 0;
}