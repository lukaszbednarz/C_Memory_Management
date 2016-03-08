#include "stdafx.h"
#include <stdlib.h>
#include "Array.h"
 

struct hidden_tag
{
	int m_size;
	int * m_data;

};

 

Array* ArrayAlloc(int size)

{

    // allocate memory for the Array stucture (use malloc)

    Array* ret = (Array *)malloc(sizeof(Array));
	
	ret->m_size = size;

    // allocate memory for the growable array (use malloc)
	
    ret->m_data = (int *)malloc(size * sizeof(int));

	if (ret->m_data == NULL) {

		free(ret);
		ret = NULL;
	}
	
    return ret;

}

 

void ArrayFree(Array* array)
{
	// free up both the memory for the array
	free(array->m_data);

    // and the memory for the Array structure
	free(array);
}

 

void Array_set(Array* array, int index, int value)
{

    if (index >= array->m_size) {

        int newSize = array->m_size * 1.5;

        if (newSize <= index) { newSize = index + 1; }
		
		// allocate more memory (use realloc)
		int *temp = (int *)realloc(array->m_data, newSize*(sizeof(int)));
		if (temp != NULL)
		{
			array->m_data = temp;

			array->m_size = newSize; 
			array->m_data[index] = value;
		}

    }

}

 

int Array_size(const Array* array)

{

    return array->m_size;

}

 

int * Array_begin(Array* array)

{

    return array->m_data;

}

 

int * Array_end(Array* array)

{

    return array->m_data + array->m_size;

}
