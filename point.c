#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "point.h"


typedef struct Point_ {
    PList coordinateList;
    int dim_num;
    int cur_dim_num;
} point;

PPoint PointCreate(int newDim_num)
{
    if(!newDim_num)
        return NULL;
    PPoint newPoint;
    newPoint = (PPoint)malloc(sizeof(point));
    if (newPoint == NULL)
        return NULL;//$$check if that what we should do here
    //inserting integers.
    newPoint->dim_num = newDim_num;
    newPoint->cur_dim_num = 0;
    newPoint->coordinateList = ListCreate(cloneCoordinate, destroyCoordinate, compareCoordinates, printCoordinate);

    return newPoint;
}

void PointDestroy(PElem elem)
{
    if(!elem)
        return;
    PPoint Point = (PPoint)elem;
    ListDestroy(Point->coordinateList);
    free((Point));
}

Result PointAddCoordinate(PPoint Point, int newCord)
{
    if(!Point || !newCord)
        return  FAIL;
    if (Point->cur_dim_num < Point->dim_num)//check if there's less cors than the dimension
    {
        int* pCord;
        if (!(pCord = (int*)malloc(sizeof(int))))
            return FAIL;
        *pCord = newCord;
        if (!ListAdd(Point->coordinateList, pCord)) {
            free(pCord);
            return FAIL;
        }
        free(pCord);
        (Point->cur_dim_num)++;
        return SUCCESS;
    }
    return FAIL;
}

int PointGetFirstCoordinate(PPoint point)
{
    if(!point)
        return 0;
    if (point->cur_dim_num == 0)
        return 0;//$$make sure all funcs calling this func make sure they dont ask for more cords than the point dimension
    int* retPointer = (int*)ListGetFirst(point->coordinateList);
    if (retPointer)
        return *(retPointer);
    return 0;

}

int PointGetNextCoordinate(PPoint point)
{
    if(!point)
        return 0;
    int* retPointer = (int*)ListGetNext(point->coordinateList);
    if (retPointer)
        return *(retPointer);
    return 0;
}

void PointPrint(PElem elem)
{
    if(!elem)
        return;
    PPoint point = (PPoint)elem;
    printf("Point Dimension: %d, Size: %d, Coordinates: ", point->dim_num, point->cur_dim_num);
    ListPrint(point->coordinateList);
}

/* ----------------------Functions for list ---------------------*/
void printCoordinate(PElem elem)
{
    if(!elem)
        return;
    int* coordinate = (int*)elem;
    printf("%d ", *coordinate);

}

BOOL compareCoordinates(PElem elem1, PElem elem2)
{
    if(!elem1 || !elem2)
        return FALSE;//$$what should we return here?
    int* coordinate1 = (int*)elem1;
    int* coordinate2 = (int*)elem2;
    if (*coordinate1 == *coordinate2)
        return true;
    return false;
}

PElem cloneCoordinate(PElem elem)
{
    if(!elem)
        return  NULL;
    int* coordinate = (int*)elem;
    int* newCoordinate;
    newCoordinate = (int*)malloc(sizeof(int));
    if (newCoordinate == NULL)
        return NULL;

    //inserting integers
    *newCoordinate = *coordinate;
    //PElem returnpointer = (PElem) newCoordinate;
    return newCoordinate;
}

void destroyCoordinate(PElem elem)
{
    if(!elem)
        return;
    int* coordinate = (int*)elem;
    free(coordinate);
}

/*-------------------------------functions for Cluster (point list)----------------------*/

PElem ClonePoint(PElem elem)
{
    if(!elem)
        return NULL;
    PPoint point = (PPoint)elem;
    int Cord;

    PPoint newPoint = PointCreate(point->dim_num);

    Cord = PointGetFirstCoordinate(point);
    if (Cord == 10000)//10000 is the return value from getfirst if there's no coordinates
        return newPoint; //empty point
    PointAddCoordinate(newPoint, Cord);
    while (Cord != 10000)
    {
        Cord = PointGetNextCoordinate(point);
        if (Cord != 10000)
            PointAddCoordinate(newPoint, Cord);
    }
    //PElem casting
    return newPoint;
}
BOOL ComparePoints(PElem elem1, PElem elem2)
{
    if(!elem1 || !elem2)
        return FALSE;//$$what should we return here?
    PPoint point1 = (PPoint)elem1;
    PPoint point2 = (PPoint)elem2;
    if ((point1->dim_num != point2->dim_num) || (point1->cur_dim_num != point2->cur_dim_num))
        return  FALSE;
    if (ListCompare(point1->coordinateList, point2->coordinateList))
        return TRUE;
    return  FALSE;
}

int PointGetDim(PPoint point)
{
    if (!point)
        return 0;
    else
        return point->dim_num;
}

int PointGetCurDim(PPoint point)
{
    if (!point)
        return 0;
    else
        return point->cur_dim_num;
}

int GetPointsDis(PPoint point1, PPoint point2)
{
    if(!point1 || !point2)
        return 0;//$$what should we return here?
    if (point1->dim_num != point2->dim_num)
        return -1;
    int dis = 0;
    int *Cod1 = ListGetFirst(point1->coordinateList);
    int *Cod2 = ListGetFirst(point2->coordinateList);

    while(Cod1)
    {
        dis = ((*Cod1 - *Cod2) * (*Cod1 - *Cod2)) + dis;
        Cod1 = ListGetNext(point1->coordinateList);
        Cod2 = ListGetNext(point2->coordinateList);
    }
    return dis;
}