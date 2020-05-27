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
    // User Functions that we need to add

} List;


pList ListCreate(/*pointers to all functions*/) {
    /*if (pointers to all functions== NULL) // any of the arguments is null return null
        return NULL;*/
    pList pNewlist;
    pNewlist = (pList)malloc(sizeof(List));
    node* pNewHead = (node*)malloc(sizeof(Node));
    if (pNewlist == NULL || pNewHead == NULL) {
        free(pNewlist);
        free(pNewHead);
        return NULL;//$$we need to check what to do if this happens (maybe exit(-1)??)
    }
    pNewHead->element = NULL; //initiaing element to NULL
    pNewHead->next = NULL;
    //saving pointers to database
    pNewlist->pHead = pNewHead;
    pNewlist->Cur_Node = pNewHead;
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
        free(pCurNode);
    }
    free(List);
}

Status ListAdd(pList List , node* node)
{
    if (List == NULL || node == NULL )
        return FAIL;

    node* pNewNode = (node*)malloc(sizeof(Node));
    if(pNewNode == NULL)
        return FAIL;

    pNewNode->element = node->element;
    node* Cur_Node = List->pHead;
    while(Cur_Node->next != Null)
        node* Cur_Node = Cur_Node->next;
    List->Cur_Node->next = pNewNode;

}

Status ListRemove(pList List , node* node)
{
    if (List == NULL || node == NULL )
        return FAIL;


    node* Cur_Node = List->pHead;
    if (Cur_Node == node )
        List->pHead = List->pHead->next;
    else
    {
        while(Cur_Node->next != node)
            node* Cur_Node = Cur_Node->next;
        if(Cur_Node == NULL )				//if the func didnt find the recived node, it returns FAIL
            return FAIL;
        List->Cur_Node->next = node->next;
    }
    free(node);
    return Success
}

node* ListGetFirst(pList List)
{
    if (List == NULL  )
        exit(-1);//$$ check if we should exit.

    List->Node_Iterator=List->pHead;
    return List->pHead;
}

node* ListGetNext(pList List)
{
    if (List == NULL  )
        exit(-1);//$$ check if we should exit.

    if(List->Node_Iterator->next == NULL)	// iterator is in the end of the list.
        return NULL;

    node* return_node = List->Node_Iterator;
    List->Node_Iterator=List->Node_Iterator->next;
    return return_node;
}

bool ListCompare(pList list_1, pList list_2)
{
    if (list_1 == NULL || list_2 == NULL )
        exit(-1);//$$ check what should we do (this ir return false).

    node* cur_node_1 = list_1->pHead;
    node* cur_node_2 = list_2->pHead;

    while(cur_node_1 != NULL || cur_node_2 != NULL )
    {
        if( cur_node_1->element != cur_node_2->element)
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
        printf("


}



























