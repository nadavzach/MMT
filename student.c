#include "list.h"
#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Student_ {
    char* name;
    int age, ID;
    char* faculty;
};


PStudent StudentCreate(char* Name, int Age, int ID, char* faculty)
{
    PStudent new_student;
    new_student = (PStudent)malloc(sizeof(Student));
    if (new_student == NULL)
        return NULL;//$$check if that what we should do here
    new_student->age = Age;
    new_student->faculty = faculty;
    new_student->ID = ID;
    new_student->name = Name;
    return new_student;
}


void printStudent(PStudent pstudent)
{

    printf("Name: %s, Age: %d, ID: %d, Faculty: %s \n" , pstudent->name,
           pstudent->age, pstudent->ID, pstudent->faculty );

}

BOOL compareStudents(PStudent pstudent1, PStudent pstudent2)
{
    if (pstudent1->ID == pstudent2->ID)
        return true;
    return false;
}

PStudent cloneStudent(PStudent pstudent)
{
    PStudent newstudent;
    newstudent = (PStudent)malloc(sizeof(Student));
    if (newstudent == NULL)
        return NULL;
    newstudent->age = pstudent->age;
    newstudent->faculty = pstudent->faculty;
    newstudent->ID = pstudent->ID;
    newstudent->name = pstudent->name;
    return newstudent;
}

void destroyStudent(PStudent pstudent)
{
    free(pstudent);
}
