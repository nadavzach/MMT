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

PStudent* cloneStudent(PStudent pstudent)
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


