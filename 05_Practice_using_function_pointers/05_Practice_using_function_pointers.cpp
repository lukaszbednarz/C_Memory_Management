// 05_Practice_using_function_pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//•Create a typedef for each of the function pointer types you created above and replace the parameters in the foreach and transform functions with the new type names.
typedef void(*PrintFP)(int) ;
typedef int(*TransferFP)(int) ;

//•Add the correct type for the third parameter of the below function to be a pointer to a function that returns void and takes an integer as its parameter.
void foreach(int *begin, int *end, PrintFP fn)
{
  while (begin != end)
  {
    fn(*begin);
    ++begin;
  }
}

//• Now create a function named print that takes an integer and returns void. Have it print out the integer passed in followed by a space.
void print(int in)
{
	printf("%d ", in);
}


//• Add the correct type for the third parameter of the below function to be a pointer to a function that returns an integer and takes an integer as its parameter
void transform(int *begin, int *end, TransferFP fn)

{

  while (begin != end)

  {

    *begin = fn(*begin);

    ++begin;

  }

}


//•Create a function named timesTwo that returns an integer and takes an integer. Have it multiply the passed in value by two and return the result.
int timesTwo(int in)
{
	return 2 * in; 
}



//•Write a main function that creates an array of 5 integers initializes them to different values then prints them out using the above foreach and print functions
int _tmain(int argc, _TCHAR* argv[])
{
	int a[5];
	int i;

    for (i = 0; i < 5; ++i) {
		a[i] = i + i;

    }

	//use foreach and print here
	PrintFP fn;
	fn = print;
    
	foreach(a, a+5, fn);
	printf("\n");

	//•Take the array you have initialized already and invoke the transform function on it using the timesTwo function.
	TransferFP trfn;
	trfn = timesTwo;

	transform(a, a+5, trfn);
	
	//•Use foreach and print to print the array out again.
	foreach(a, a+5, fn);
	printf("\n");

	return 0;
}

