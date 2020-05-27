#ifndef _LIST_H_
#define _LIST_H_
#include "defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List_* pList;
typedef void* PElem;
typedef enum {  Fail , Success } Status;

// constructor
pList ListCreate(/*pointers to all functions*/);

//destroyer

void ListDestroy(pList List);

/*User functions*/

typedef int (*ListRemove)(PElem);
typedef void * (*ListRemove)(PElem);



/*Interface functions*/
Status ListAdd(pList List , Node node);
#endif