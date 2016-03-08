// 02_Practice_using_pointers_with_structures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//•Declare an structure and typedef it Point with two integers as members
typedef struct Point
{
	int x;
	int y;

} Point; 

void scalePoint(Point *ptp, int scale);


int _tmain(int argc, _TCHAR* argv[])
{
	//•Declare a variable of type Point named 'p' and assign values for x and y
	Point p;
	p.x = 1;
	p.y = 2;

	//•Declare a variable of type pointer to Point named 'ptp' and have it point to 'p'.
	Point *ptp;
	ptp = &p;

	//•Change the value of p.x and p.y using 'ptp'
	ptp->x = 3;
	ptp->y = 4;
	
	//•Print out the value of p.x and p.y 
	printf("x=%d y=%d\n", p.x, p.y);

	//•Call the 'scalePoint' function passing 'ptp' for the first parameter and 3 for the second
	scalePoint(ptp, 3);
	
	//•Print out the value of p.x and p.y again
	printf("x=%d y=%d\n", p.x, p.y);	
	
	return 0;
}

//•Write a function named 'scalePoint' that returns void and takes a pointer to a Point and an integer as parameters. You function should multiply each member of the Point structure passed in the first parameter by the second parameter.
void scalePoint(Point *ptp, int scale) {
	ptp->x *= scale;
	ptp->y *= scale;
}