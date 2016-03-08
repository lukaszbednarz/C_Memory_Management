// 01_Practice_using_pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void timesTwo(int *i);

int _tmain(int argc, _TCHAR* argv[])
{
	
	//•  Declare three variables named x, y and z that are integers
	int x,y,z;

	//•  Assign the value 8 to x, 16 to y and 12 to z
	x =8;
	y =16;
	z = 12;

	//•  Create a variable named ptr that is a pointer to an integer
	int *ptr;

	//•  Assign the address of x to ptr using the & operator
	ptr = &x;

	//•  Change the value of the integer, to which ptr points, to 32
	x = 32;

	//•  Assign the address of y to ptr using the & operator
	ptr = &y;

	//•  Change the value of the integer, to which ptr points, to 64
	y = 64;

	//•  Print out the value of x and y
	printf("x = %d\ny = %d\n", x, y); 
	
	
	//•  Pass the address of z to the function timesTwo
		timesTwo(&z);

	//•  Print out the value of z

	printf("z = %d", z);
	
}

	//•  Define a function timesTwo returns void and takes a pointer to an integer
	//•  Have the function change the value of the pointed to integer to two times the original value

	void timesTwo(int *i) { 
		*i *= 2;
	}
