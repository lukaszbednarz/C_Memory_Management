// 08_Practice_adjusting_structure_members.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma pack(push, 1)
typedef struct
{
    int i;
    short s;
	char c;
} SimpleStruct;
#pragma pack(pop)


int _tmain(int argc, _TCHAR* argv[])
{
	
	printf("Size of SimpleStruct: %d", sizeof(SimpleStruct));
	
	return 0;
}

