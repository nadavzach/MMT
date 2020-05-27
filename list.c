#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "list.h"

typedef struct node {
    struct node* next;
    PElem element;
} Node;

typedef struct List_ {
    node* pHead;
    node* Node_Iterator;

    // functions recived from the user

    CLONE_ELEM cloneElem;
    REMOVE_ELEM removeElem;
    COMPARE_ELEM compareElem;
    PRINT_ELEM printElem;
} List;


pList ListCreate(CLONE_ELEM pCloneElem, REMOVE_ELEM pRemoveElem, COMPARE_ELEM pCompareElem, PRINT_ELEM pPrintElem) {
    if (pCloneElem == NULL || pRemoveElem == NULL || pCompareElem == NULL || pPrintElem == NULL ) // any of the arguments is null return null
        return NULL;
    pList pNewlist;
    pNewlist = (pList)malloc(sizeof(List));
    node* pNewHead = (node*)malloc(sizeof(Node));
    if (pNewlist == NULL || pNewHead == NULL) {
        free(pNewlist);
        free(pNewHead);
        return NULL;//$$we need to check what to do if this happens (maybe exit(-1)??)
    }
    pNewHead->element = NULL; //initiating element to NULL
    pNewHead->next = NULL;
    //saving pointers to first node
    pNewlist->pHead = pNewHead;
    pNewlist->Node_Iterator = pNewHead;
    //inserting user funcs to the list
    pNewlist->cloneElem = pCloneElem;
    pNewlist->removeElem = pRemoveElem ;
    pNewlist->compareElem = pCompareElem;
    pNewlist->printElem = pPrintElem;
    return pNewlist;
}

void ListDestroy(pList List) {
    if (List == NULL) // checking for input
        return;
    Node * pCurNode;
    while (List->pHead)
    {

        pCurNode = List->pHead;
        List->pHead = List->pHead->next;
        list->removeElem(pCurNode->element);
        free(pCurNode);
    }
    free(List);
}

Status ListAdd(pList List , PElem newElem)
{
    if (List == NULL || newElem == NULL )
        return Fail;

    node* pNewNode = (node*)malloc(sizeof(Node));
    if(pNewNode == NULL)
        return Fail;
    pNewNode->element = newElem;//adding the new element to the new node


    node* Cur_Node = List->pHead;
    while(Cur_Node->next != Null)
         Cur_Node = Cur_Node->next;
    List->Cur_Node->next = pNewNode;

}

Status ListRemove(pList List , PElem elem_to_rem)
{
    if (List == NULL || elem_to_rem == NULL )
        return Fail;

    node* Node_to_remove;
    node* Cur_Node = List->pHead;
    if (list->compareElem(Cur_Node->element, elem_to_rem) )
    {
        List->pHead = List->pHead->next;
        Node_to_remove = Cur_node;
    }
    else
    {
        while(!(list->compareElem(Cur_Node->next->element, elem_to_rem)))
            node* Cur_Node = Cur_Node->next;
        if(Cur_Node == NULL )				//if the func didnt find the recived node, it returns Fail
            return Fail;
        Node_to_remove = Cur_Node->next;
        Cur_Node->next = Cur_Node->next->next;
    }
    list->removeElem(Node_to_remove->next->element);
    free(Node_to_remove);
    return Success
}

node* ListGetFirst(pList List)
{
    if (List == NULL  )
        exit(-1);//$$ check if we should exit.

    List->Node_Iterator=List->pHead;
    return List->pHead->element;
}

node* ListGetNext(pList List)
{
    if (List == NULL)
        exit(-1);//$$ check if we should exit.

    if(List->Node_Iterator->next == NULL)	// iterator is in the end of the list.
        return NULL;

    node* return_node = List->Node_Iterator;
    List->Node_Iterator=List->Node_Iterator->next;
    return return_node->element;
}

bool ListCompare(pList list_1, pList list_2)
{
    if (list_1 == NULL || list_2 == NULL )
        exit(-1);//$$ check what should we do (this ir return false).

    node* cur_node_1 = list_1->pHead;
    node* cur_node_2 = list_2->pHead;

    while(cur_node_1 != NULL || cur_node_2 != NULL )
    {
        if( list->compareElem(cur_node_1->element, cur_node_2->element)
            return false;
        cur_node_1=cur_node_1->next;
        cur_node_2=cur_node_2->next;
    }
    if(cur_node_1 == NULL && cur_node_2 == NULL)
        return true;
    return false;
}


void ListPrint(pList List)
{
    printf("[");
    node* cur_node = List->pHead;
    while(cur_node != NULL)
    {
        list->printElem(cur_node->element);
        cur_node = cur_node->next;
    }
    printf("]\n");

}



























