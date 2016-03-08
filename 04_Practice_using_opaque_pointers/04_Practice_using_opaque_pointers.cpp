// 04_Practice_using_opaque_pointers.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Student.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//•Write a main function in another file, e.g. main.c, have it include "Student.h" and have it test the Student interface.
	Student* student = newStudent(65432);

	Student_setName(student, "Bradley");

	printf("%s's student id is %d.\n", Student_getName(student),

									   Student_getId(student));

	deleteStudent(student);

		
	return 0;
}

