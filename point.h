#ifndef _POINT_H_
#define _POINT_H_

#include "defs.h"
typedef struct Point_* PPoint;

PPoint PointCreate(int newDim_num);
void PointDestroy(PElem elem);
Result PointAddCoordinate(PPoint Point, int newCord);
int PointGetNextCoordinate(PPoint point);
int PointGetFirstCoordinate(PPoint point);
void PointPrint(PElem elem);
int PointGetDim(PPoint point);
int GetPointsDis(PPoint point1, PPoint point2);

/*----------------Interface functions-----------------------------*/

void printCoordinate(PElem elem);
BOOL compareCoordinates(PElem elem1, PElem elem2);
PElem cloneCoordinate(PElem elem);
void destroyCoordinate(PElem elem);

/*----------------functions for Cluster (point lis--------------*/

PElem ClonePoint(PElem elem);
BOOL ComparePoints(PElem elem1, PElem elem2);

#endif