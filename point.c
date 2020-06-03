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
    if (!newDim_num)
        return NULL;
    PPoint newPoint;
    newPoint = (PPoint)malloc(sizeof(point));
    if (newPoint == NULL)
        return NULL;
    //inserting integers.
    newPoint->dim_num = newDim_num;
    newPoint->cur_dim_num = 0;
    newPoint->coordinateList = ListCreate(cloneCoordinate, destroyCoordinate, compareCoordinates, printCoordinate);

    return newPoint;
}

void PointDestroy(PElem elem)
{
    if (!elem)
        return;
    PPoint Point = (PPoint)elem;
    ListDestroy(Point->coordinateList);
    free(Point);
}
void PointCordListDestroy(PElem elem) //same as
{
    if (!elem)
        return;
    PPoint Point = (PPoint)elem;
    ListDestroy(Point->coordinateList);
}

Result PointAddCoordinate(PPoint Point, int newCord)
{
    if (!Point)
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
    if (!point)
        return 0;
    if (point->cur_dim_num == 0)
        return 0;
    int* retPointer = (int*)ListGetFirst(point->coordinateList);
    if (retPointer)
        return *(retPointer);
    return 0;

}

int PointGetNextCoordinate(PPoint point)
{
    if (!point)
        return 0;
    int* retPointer = (int*)ListGetNext(point->coordinateList);
    if (retPointer)
        return *(retPointer);
    return 0;
}

void PointPrint(PElem elem)
{
    if (!elem)
        return;
    PPoint point = (PPoint)elem;
    printf("Point Dimension: %d, Size: %d, Coordinates: ", point->dim_num, point->cur_dim_num);
    ListPrint(point->coordinateList);
}

/* ----------------------Functions for list ---------------------*/
void printCoordinate(PElem elem)
{
    if (!elem)
        return;
    int* coordinate = (int*)elem;
    printf("%d ", *coordinate);

}

BOOL compareCoordinates(PElem elem1, PElem elem2)
{
    if (!elem1 || !elem2)
        return FALSE;
    int* coordinate1 = (int*)elem1;
    int* coordinate2 = (int*)elem2;
    if (*coordinate1 == *coordinate2)
        return true;
    return false;
}

PElem cloneCoordinate(PElem elem)
{
    if (!elem)
        return  NULL;
    int* coordinate = (int*)elem;
    int* newCoordinate;
    newCoordinate = (int*)malloc(sizeof(int));
    if (newCoordinate == NULL)
        return NULL;

    //inserting integers
    *newCoordinate = *coordinate;
    return newCoordinate;
}

void destroyCoordinate(PElem elem)
{
    if (!elem)
        return;
    int* coordinate = (int*)elem;
    free(coordinate);
}

/*-------------------------------functions for Cluster (point list)----------------------*/

PElem ClonePoint(PElem elem)
{
    if (!elem)
        return NULL;
    PPoint point = (PPoint)elem;
    int Cord;
    int i;

    PPoint newPoint = PointCreate(point->dim_num);

    if (point->cur_dim_num == 0)//meaning the point is empty.
        return newPoint; //empty point
    Cord = PointGetFirstCoordinate(point);
    PointAddCoordinate(newPoint, Cord);

    for (i = 2; i <= point->cur_dim_num; i++)
    {
        Cord = PointGetNextCoordinate(point);
        PointAddCoordinate(newPoint, Cord);
    }
    return newPoint;
}
BOOL ComparePoints(PElem elem1, PElem elem2)
{
    if (!elem1 || !elem2)
        return FALSE;
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

int GetPointsDis(PPoint point1, PPoint point2)
{
    if (!point1 || !point2)
        return 0;
    if (point1->dim_num != point2->dim_num)
        return -1;
    int dis = 0;
    int* Cod1 = ListGetFirst(point1->coordinateList);
    int* Cod2 = ListGetFirst(point2->coordinateList);
    int pointDim = point1->dim_num;
    int i;
    for (i = 0; i < pointDim; i++)//we can assume that all points are full with their cords'.(from forum)
    {
        dis = ((*Cod1 - *Cod2) * (*Cod1 - *Cod2)) + dis;
        Cod1 = ListGetNext(point1->coordinateList);
        Cod2 = ListGetNext(point2->coordinateList);
    }
    return dis;
}