// 03_Practice_with_malloc_free_and_realloc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Array.h"
 
void print(int * begin, int * end)

{

    while (begin != end) {

        printf("%d ", *begin);

        ++begin;

    }

    printf("\n");

}

 

int _tmain(int argc, _TCHAR* argv[])
{
	Array* arr = ArrayAlloc(10);

    int *it = NULL;

    int i = 0;

    int size = 0;

    

    it = Array_begin(arr);

    size = Array_size(arr);

 

    for (i = 0; i < size; ++i) {

        it[i] = i + i;

    }

    

    print(Array_begin(arr), Array_end(arr));

    

    // This will grow the array because we are setting an

    // index that is larger than the last index

    Array_set(arr, size, 42);

    

    print(Array_begin(arr), Array_end(arr));
	 

    // Need to make sure and free the memory allocated

    ArrayFree(arr);

	return 0;
}


