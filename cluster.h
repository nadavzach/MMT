#ifndef _CLUSTER_H_
#define _CLUSTER_H_
#include "defs.h"
#include "point.h"

typedef struct Cluster_* PCluster;

/*Interface functions*/
void ClusterDestroy(PCluster cluster);
PCluster ClusterCreate(int newDim);
Result ClusterAddPoint(PCluster cluster, PPoint point);
int ClusterGetMinDistance(PCluster cluster, PPoint point);
void ClusterPrint(PCluster cluster);


#endif