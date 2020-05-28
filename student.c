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
    //inserting integers.
    new_student->age = Age;
    new_student->ID = ID;

    //mallocing and cpying strings
    if(NULL==(new_student->faculty = (char*)malloc(sizeof(strlen(faculty)+1)))) {
        free(new_student);
        return NULL;
    }
    strcpy(new_student->faculty , faculty);

    if(NULL==(new_student->name = (char*)malloc(sizeof(strlen(Name)+1))))
    {
        free(new_student->faculty);
        free(new_student);
        return NULL;
    }
    strcpy(new_student->name , Name);
    return new_student;
}


void printStudent(PStudent pstudent)
{

    printf("Name: %s, Age: %d, ID: %d, Faculty: %s \n", pstudent->name,
           pstudent->age, pstudent->ID, pstudent->faculty);

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

    //inserting integers
    newstudent->age = pstudent->age;
    newstudent->ID = pstudent->ID;

    //mallocing and copying strings
    if(NULL==(newstudent->faculty = (char*)malloc(sizeof(strlen(pstudent->faculty)+1)))) {
        free(newstudent);
        return NULL;
    }
    strcpy(newstudent->faculty , pstudent->faculty);

    if(NULL==(newstudent->name = (char*)malloc(sizeof(strlen(pstudent->name)+1)))) {
        free(newstudent->faculty);
        free(newstudent);
        return NULL;
    }
    strcpy(newstudent->name , pstudent->name);
    return newstudent;
}

void destroyStudent(PStudent pstudent)
{
    free(pstudent->name);
    free(pstudent->faculty);
    free(pstudent);
}