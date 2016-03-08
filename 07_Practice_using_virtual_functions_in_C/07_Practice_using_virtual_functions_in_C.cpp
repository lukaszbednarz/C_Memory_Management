// 07_Practice_using_virtual_functions_in_C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

typedef struct Animal Animal;

typedef struct
{
    void (*speak)(Animal* self);
} Animal_vtbl;


struct Animal
{
    Animal_vtbl * vtbl;
};

void Animal_speak(Animal* self)
{
    printf("growl");
}

static Animal_vtbl the_Animal_vtbl = { Animal_speak };

void Animal_ctor(Animal* self)
{
    self->vtbl = &the_Animal_vtbl;
}

// Create a subclass Dog that provides a different implementation for speak (have it print out "woof") 
// and in the Dog_ctor have it set the vtbl to point to its implementation.

typedef struct Dog Dog;

struct Dog 
{
	Animal base;
};

void Dog_speak(Animal* self)
{
    printf("woof");
}

static Animal_vtbl the_Dog_vtbl = { Dog_speak };

void Dog_ctor(Dog *self)
{
	Animal_ctor((Animal *) self);
	self->base.vtbl = &the_Dog_vtbl;

}


void speak(Animal *animals[], int size)
{
    int i;

	for (i = 0; i < size; ++i)
    {
		animals[i]->vtbl->speak(animals[i]);
        printf("\n");
    }
}



int _tmain(int argc, _TCHAR* argv[])
{
	// Use the below code to see if your implementation works. 
	Dog spot, fido;
	Animal wild1;
    Animal * animals[3];
	 

    Dog_ctor(&spot);
	Dog_ctor(&fido);
	Animal_ctor(&wild1);
	
    animals[0] = (Animal *)&spot;
    animals[1] = &wild1;
	animals[2] = (Animal *)&fido;

    speak(animals, 3);

	return 0;
}

