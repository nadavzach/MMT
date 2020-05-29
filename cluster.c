#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "point.h"
#include "cluster.h"

typedef struct Cluster_ {
    PList pointList;
    int Cluster_dim;
    int minDistance;
} cluster;

PCluster ClusterCreate(int newDim)
{
    PCluster newCluster;
    newCluster = (PCluster)malloc(sizeof(cluster));
    if (newCluster == NULL)
        return NULL;//$$check if that what we should do here
    //inserting integers.
    newCluster->Cluster_dim = newDim;
    newCluster->pointList = ListCreate(ClonePoint, PointDestroy, ComparePoints, PointPrint);
    newCluster->minDistance = -1;

    return newCluster;
}

void ClusterDestroy(PCluster cluster)
{
    ListDestroy(cluster->pointList);
    free(cluster);
}

Result ClusterAddPoint(PCluster cluster, PPoint point)
{
    if (PointGetDim(point) != cluster->Cluster_dim)
        return FAIL;
    /*-------checking if the point exists---------*/
    PPoint curPoint = ListGetFirst(cluster->pointList);
    while (curPoint)
    {
        if (ComparePoints(point, curPoint))
            return FAIL;
        curPoint = ListGetNext(cluster->pointList);
    }
    cluster->minDistance = ClusterGetMinDistance(cluster, point);
    ListAdd(cluster->pointList, ClonePoint(point));
    return SUCCESS;
}

int ClusterGetMinDistance(PCluster cluster, PPoint point)
{
    PPoint curPoint = ListGetFirst(cluster->pointList);
    if (curPoint == NULL)// there arent any points to compare with yet
        return -1;
    int curmindis = cluster->minDistance;
    int* MinDis;
    MinDis = (int*)malloc(sizeof(int));
    while (curPoint)
    {
        *MinDis = GetPointsDis(point, curPoint);
        if ((cluster->minDistance) == -1) // for the first point inside
            return *MinDis;
        if (*MinDis < curmindis) // updateing min sum
            curmindis = *MinDis;
    }
    *MinDis = curmindis;
    return *MinDis;
}

void ClusterPrint(PCluster cluster)
{
    printf("Cluster's dimension: %d\n", cluster->Cluster_dim);
    ListPrint(cluster->pointList);
    printf("Minimum Square Distance: %d\n", cluster->minDistance);


}
