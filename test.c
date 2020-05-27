#include "list.h"
#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student_ Student, * PStudent;

struct Student_ {
	int age;
};

int main()
{
	char Line[MAX_LINE_SIZE];
	char* delimiters = " \t\n";
	char* Command;
	PList pStudentList1 = NULL;
	PList pStudentList2 = NULL;
	pStudentList1 = ListCreate(cloneStudent, destroyStudent, compareStudents, printStudent);
	pStudentList2 = ListCreate(cloneStudent, destroyStudent, compareStudents, printStudent);
	if (!pStudentList)
	{
		printf("ListCreate for Student Failed. Exiting.\n");
		exit(-1);
	}
	ListAdd(pStudentList1, 45);
	ListAdd(pStudentList1, 21);
	ListAdd(pStudentList1, 45);
	ListAdd(pStudentList1, 21);
	ListAdd(pStudentList2, 45);
	ListRemove(pStudentList1, 45);
	ListGetFirst(pStudentList1);
	ListGetNext(pStudentList1);
	ListCompare(pStudentList1, pStudentList2);
	ListAdd(pStudentList2, 45);
	ListCompare(pStudentList1, pStudentList2);
	ListPrint(pStudentList1);
	ListPrint(pStudentList2);
}

void printstudentlist(int age) {
	
	printf("The student's age is : %d \n" , &age );
	
}


