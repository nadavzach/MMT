#ifndef _STUDENT_H_
#define _STUDENT_H_

typedef struct Student_ Student, *PStudent;

PStudent StudentCreate(char* Name, int Age, int ID, char* faculty);

void printStudent(PStudent );
BOOL compareStudents(PStudent , PStudent );
PStudent cloneStudent(PStudent);
void destroyStudent(PStudent);

#endif