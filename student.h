#ifndef _STUDENT_H_
#define _STUDENT_H_

typedef struct Student_ Student, *PStudent;


void printStudent(PStudent );
BOOL compareStudents(PStudent , PStudent );
PStudent* cloneStudent(PStudent);
void destroyStudent(PStudent);

#endif
