#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    newPoint->coordinateList = ListCreate(cloneCoordinate,destroyCoordinate,compareCoordinates, printCoordinate );

    return newPoint;
}

void PointDestroy(PPoint Point)
{
   ListDestroy(Point->coordinateList);
   free((Point));
}

Result PointAddCoordinate(PPoint Point,int newCord)
{
    int* pCord = (int*)malloc(sizeof(int));
    *pCord = newCord;
    if(!ListAdd(Point,newCord))
        return FAIL;
    return SUCCESS;
}

int PointGetFirstCoordinate(PPoint point)
{
    if (point->cur_dim_num == 0)
        return -1;//$$??

     return *((int*)ListGetFirst(point->coordinateList));

}

int PointGetNextCoordinate(PPoint point)
{
    return *((int*)(ListGetNext(point->coordinateList)));
}

void PointPrint(PPoint point)
{
    printf("Point Dimension: %d, Size: %d, Coordinates: ",point->dim_num,point->cur_dim_num);
    ListPrint(point->coordinateList);
}

 /*      Functions for list        */
void printCoordinate(int* coordinate)
{
    printf("%d",*coordinate);

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