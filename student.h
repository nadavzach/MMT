#ifndef _STUDENT_H_
#define _STUDENT_H_

typedef struct Student_ Student, * PStudent;

PStudent StudentCreate(char* Name, int Age, int ID, char* faculty);

void printStudent(PElem);
BOOL compareStudents(PElem, PElem);
PElem cloneStudent(PElem);
void destroyStudent(PElem);

#endif