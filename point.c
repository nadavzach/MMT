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

void PointDestroy(PPoint Point)
{
    ListDestroy(Point->coordinateList);
    free((Point));
}

Result PointAddCoordinate(PPoint Point, int newCord)
{
    if (Point->cur_dim_num < Point->dim_num)//check if theres less cors than the dimention
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
    if (point->cur_dim_num == 0)
        return 0;//$$??
    int* retPointer = (int*)ListGetFirst(point->coordinateList);
    if (retPointer)
        return *(retPointer);
    return 0;

}

int PointGetNextCoordinate(PPoint point)
{
    int* retPointer = (int*)ListGetNext(point->coordinateList);
    if (retPointer)
        return *(retPointer);
    return 0;
}

void PointPrint(PPoint point)
{
    printf("Point Dimension: %d, Size: %d, Coordinates: ", point->dim_num, point->cur_dim_num);
    ListPrint(point->coordinateList);
}

/* ----------------------Functions for list ---------------------*/
void printCoordinate(int* coordinate)
{
    printf("%d ", *coordinate);

}

BOOL compareCoordinates(int* coordinate1, int* coordinate2)
{
    if (*coordinate1 == *coordinate2)
        return true;
    return false;
}

int* cloneCoordinate(int* coordinate)
{
    int* newCoordinate;
    newCoordinate = (int*)malloc(sizeof(int));
    if (newCoordinate == NULL)
        return NULL;

    //inserting integers
    *newCoordinate = *coordinate;

    return newCoordinate;
}

void destroyCoordinate(int* coordinate)
{
    free(coordinate);
}

/*-------------------------------functions for Cluster (point list)----------------------*/

PPoint ClonePoint(PPoint point)
{
    int Cord;

    PPoint newPoint = PointCreate(point->dim_num);

    Cord = PointGetFirstCoordinate(point);
    if (Cord == 0)//0 is the return value from getfirst if there's no coordinates
        return newPoint; //empty point
    PointAddCoordinate(newPoint, Cord);
    while (Cord != 0)
    {
        Cord = PointGetNextCoordinate(point);
        if (Cord != 0)
            PointAddCoordinate(newPoint, Cord);
    }
    return newPoint;
}
BOOL ComparePoints(PPoint point1, PPoint point2)
{
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
    if (point1->cur_dim_num != point2->cur_dim_num)
        return -1;
    int* dis;
    dis = (int*)malloc(sizeof(int));
    if (dis == NULL)
        return NULL;
    int* Cod1 = (int*)ListGetFirst(point1->coordinateList);
    int* Cod2 = (int*)ListGetFirst(point1->coordinateList);

    for (int i = 0; i < point1->cur_dim_num; i++)
    {
        dis = ((*Cod1 - *Cod2) * (*Cod1 - *Cod2)) + dis;
    }
    return *dis;
}
