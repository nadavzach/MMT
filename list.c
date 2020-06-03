#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct node {
    pNode next;
    PElem element;
} Node;

typedef struct List_ {
    pNode pHead;
    pNode Node_Iterator;

    // functions recived from the user

    CLONE_ELEM cloneElem;
    REMOVE_ELEM removeElem;
    COMPARE_ELEM compareElem;
    PRINT_ELEM printElem;
} List;


PList ListCreate(CLONE_ELEM pCloneElem, REMOVE_ELEM pRemoveElem, COMPARE_ELEM pCompareElem, PRINT_ELEM pPrintElem) {
    if (pCloneElem == NULL || pRemoveElem == NULL || pCompareElem == NULL || pPrintElem == NULL) // any of the arguments is NULL return NULL
        return NULL;
    PList pNewlist;
    pNewlist = (PList)malloc(sizeof(List));
    if (pNewlist == NULL) {
        free(pNewlist);
        return NULL;
    }
    //saving pointers to first node
    pNewlist->pHead = NULL;
    pNewlist->Node_Iterator = NULL;
    //inserting user funcs to the list
    pNewlist->cloneElem = pCloneElem;
    pNewlist->removeElem = pRemoveElem;
    pNewlist->compareElem = pCompareElem;
    pNewlist->printElem = pPrintElem;
    return pNewlist;
}

void ListDestroy(PList List) {
    if (List == NULL) // checking for input
        return;
    Node* pCurNode;
    while (List->pHead)
    {

        pCurNode = List->pHead;
        List->pHead = List->pHead->next;
        List->removeElem(pCurNode->element);
        free(pCurNode);
    }
    free(List);
}

Result ListAdd(PList List, PElem newElem)
{
    if (List == NULL || newElem == NULL)
        return FAIL;

    pNode pNewNode = (pNode)malloc(sizeof(Node));



    if (pNewNode == NULL)
        return FAIL;
    pNewNode->next = NULL;
    pNewNode->element = List->cloneElem(newElem);//adding the new element to the new node

    if (pNewNode->element == NULL)
        return FAIL;

    if (List->pHead == NULL)//if the list is empty the func inserts the new elem' to the head.
    {
        List->Node_Iterator = pNewNode;
        List->pHead = pNewNode;
        return SUCCESS;
    }

    pNode Cur_Node = List->pHead;
    while (Cur_Node->next != NULL)
        Cur_Node = Cur_Node->next;

    Cur_Node->next = pNewNode;
    return SUCCESS;
}

Result ListRemove(PList List, PElem elem_to_rem)
{
    if (List == NULL || elem_to_rem == NULL)
        return FAIL;

    pNode Node_to_remove;
    pNode Cur_Node = List->pHead;
    if (List->compareElem(Cur_Node->element, elem_to_rem)) // first elemt is the element to remove
    {
        List->pHead = List->pHead->next;
        Node_to_remove = Cur_Node;
    }
    else
    {

        while (Cur_Node->next != NULL)
        {
            if (List->compareElem(Cur_Node->next->element, elem_to_rem))
                break;
            Cur_Node = Cur_Node->next;
        }
        if (Cur_Node->next == NULL)
            return FAIL;

        Node_to_remove = Cur_Node->next;
        Cur_Node->next = Cur_Node->next->next;
    }
    List->removeElem(Node_to_remove->element);
    free(Node_to_remove);
    return SUCCESS;
}

PElem ListGetFirst(PList List)
{
    if (List == NULL)
        return NULL;

    List->Node_Iterator = List->pHead;
    if (List->pHead)
        return List->pHead->element;
    return NULL;
}

PElem ListGetNext(PList List)
{
    if (List == NULL)
        return NULL;

    if (List->Node_Iterator->next == NULL)	// iterator is in the end of the list.
        return NULL;

    List->Node_Iterator = List->Node_Iterator->next;

    return List->Node_Iterator->element;
}

BOOL ListCompare(PList list_1, PList list_2)
{
    if (list_1 == NULL || list_2 == NULL)
        return false;

    pNode cur_node_1 = list_1->pHead;
    pNode cur_node_2 = list_2->pHead;

    while (cur_node_1 != NULL || cur_node_2 != NULL)
    {
        if (!(list_1->compareElem(cur_node_1->element, cur_node_2->element)))
            return false;
        cur_node_1 = cur_node_1->next;
        cur_node_2 = cur_node_2->next;
    }
    if (cur_node_1 == NULL && cur_node_2 == NULL)
        return true;
    return false;
}


void ListPrint(PList List)
{
    if (!List)
        return;
    pNode cur_node = NULL;

    printf("[");
    cur_node = List->pHead;
    while (cur_node != NULL)
    {
        List->printElem(cur_node->element);
        cur_node = cur_node->next;
    }
    printf("]\n");

}
Result ListisEmpty(PList List)
{
    if (!List)
        return FAIL;
    if (List->pHead == NULL)
        return SUCCESS;
    return FAIL;

}