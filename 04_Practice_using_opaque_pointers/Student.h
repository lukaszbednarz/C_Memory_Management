#pragma once

typedef struct hidden_tag Student;

//•Create a header file named Student.h. In that file declare an opaque structure and typedef it Student.


typedef struct hidden_tag Student;

//•Also declare prototypes to several functions that will access and manipulate the abstract type. Declare one function to create a new Student, and one to delete a Student.
Student* newStudent(int id);
void deleteStudent(Student* s);

//•Declare a function to get the id.
int Student_getId(const Student* s);

//•Using the same pattern as the above function, name starts with "Student_" first parameter is pointer to Student, declare functions to get and set the name of the student, use const char* for the name.
void Student_setName(Student* s, const char * n);

char* Student_getName(const Student* s);

