#ifndef Array_h

#define Array_h

 

typedef struct hidden_tag Array;


Array* ArrayAlloc(int size);

void ArrayFree(Array* array);

 

void Array_set(Array* array, int index, int value);

int Array_size(const Array* array);

 

int * Array_begin(Array* array);

int * Array_end(Array* array);

 

#endif
