#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include "Student.h"

struct hidden_tag
{
	int id;
	char name[16];
};


//•Also declare prototypes to several functions that will access and manipulate the abstract type. Declare one function to create a new Student, and one to delete a Student.
Student* newStudent(int id)
{
	Student *s = (Student *)malloc(sizeof(Student));

	return s;
}

void deleteStudent(Student* s)
{
	free(s);
}


//•Declare a function to get the id.
int Student_getId(const Student* s)
{
	return s->id;
}


//•Using the same pattern as the above function, name starts with "Student_" first parameter is pointer to Student, declare functions to get and set the name of the student, use const char* for the name.
void Student_setName(Student* s, const char * n)
{
	strncpy(s->name, n, (sizeof(s->name))/sizeof(char));
}


char * Student_getName(const Student* s)
{
	return (char *)(s->name);
}