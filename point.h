#ifndef _POINT_H_
#define _POINT_H_

#include "defs.h"
typedef struct Point_* PPoint;

PPoint PointCreate(int newDim_num);
void PointDestroy(PPoint Point);
Result PointAddCoordinate(PPoint Point,int newCord);
int PointGetNextCoordinate(PPoint point);
int PointGetFirstCoordinate(PPoint point);
void PointPrint(PPoint point);
int PointGetDim(PPoint point);
int PointGetCurDim(PPoint point);

/*----------------Interface functions-----------------------------*/

void printCoordinate(int* coordinate);
BOOL compareCoordinates(int* coordinate1, int* coordinate2);
int* cloneCoordinate(int* coordinate);
void destroyCoordinate(int* coordinate);

/*----------------functions for Cluster (point lis--------------*/

PPoint ClonePoint(PPoint point);
BOOL ComparePoints(PPoint point1, PPoint point2);

#endif
