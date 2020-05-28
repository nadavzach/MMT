//#ifndef MMT_HMW3_LIST_H
//#define MMT_HMW3_LIST_H

//#endif //MMT_HMW3_LIST_H
#ifndef _LIST_H_
#define _LIST_H_
#include "defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List_* PList;
typedef struct node* pNode;
typedef void* PElem;
typedef enum { Fail, Success } Status;

/*User functions*/

typedef PElem(*CLONE_ELEM)(PElem);
typedef void (*REMOVE_ELEM)(PElem);
typedef BOOL(*COMPARE_ELEM)(PElem, PElem);
typedef void (*PRINT_ELEM)(PElem);


// constructor
PList ListCreate(CLONE_ELEM pCloneElem, REMOVE_ELEM pRemoveElem, COMPARE_ELEM pCompareElem, PRINT_ELEM pPrintElem);
//destroyer

void ListDestroy(PList List);



/*Interface functions*/
Status ListAdd(PList List, PElem newElem);
Status ListRemove(PList List, PElem elem_to_rem);
pNode ListGetFirst(PList List);
pNode ListGetNext(PList List);
BOOL ListCompare(PList list_1, PList list_2);
void ListPrint(PList List);
#endif