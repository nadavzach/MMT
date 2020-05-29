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
    newCluster->pointList = ListCreate(ClonePoint,PointDestroy,ComparePoints, PointPrint );

    return newCluster;
}

void ClusterDestroy( PCluster cluster)
{
    ListDestroy(cluster->pointList);
    free(cluster);
}

Result ClusterAddPoint(PCluster cluster, PPoint point)
{
    if(PointGetDim(point) != cluster->Cluster_dim)
        return FAIL;
    /*-------checking if the point exists---------*/
    PPoint curPoint=ListGetFirst(cluster->pointList);
    while (curPoint)
    {
        if(ComparePoints(point,curPoint))
            return FAIL;
        curPoint=ListGetNext(cluster->pointList);
    }
    ListAdd(cluster->pointList,ClonePoint(point));
    cluster->minDistance = ClusterGetMinDistance(cluster);
    return SUCCESS;
}

int ClusterGetMinDistance(PCluster cluster)
{

}

void ClusterPrint(PCluster cluster)
{
    printf("Cluster's dimension: %d\n",cluster->Cluster_dim);
    ListPrint(cluster->pointList);
    printf("Minimum Square Distance: %d\n",cluster->minDistance);


}


