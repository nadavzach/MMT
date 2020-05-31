#include "list.h"
#include "point.h"
#include "cluster.h"
#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char Line[MAX_LINE_SIZE];
    char* delimiters = " \t\n";
    char* Command;
    PList pStudentList=NULL;;
    //PCluster pCluster=NULL;
    pStudentList=ListCreate(cloneStudent,destroyStudent,compareStudents,printStudent);
    if(!pStudentList)
    {
        printf("ListCreate for Student Failed. Exiting.\n");
        exit(-1);
    }

    /*---------command to test point files------------*/

    PPoint test_Point = PointCreate(3);
    if(!test_Point)
    {
        printf("ListCreate for point test Failed. Exiting.\n");
        exit(-1);
    }

    /*---------end of test------------*/

    while (fgets(Line, MAX_LINE_SIZE, stdin)) {

        Command = strtok(Line, delimiters);

        if (NULL == Command) {
            continue;
        }
        /*----------------command to test point files------------*/



        if (0 == strcmp(Command, "Add_Cord"))
        {
            if(test_Point)
            {
                char* rec_cord = strtok(NULL, delimiters);
                PointAddCoordinate(test_Point,atoi(rec_cord));
            }
        }
        if (0 == strcmp(Command, "gf"))
        {
            if(test_Point)
            {
                printf("%d\n",PointGetFirstCoordinate(test_Point));
            }
        }
        if (0 == strcmp(Command, "gn"))
        {
            if(test_Point)
            {
                printf("%d\n",PointGetNextCoordinate(test_Point));
            }
        }

        /* ---------------end of point test------------------------*/
        if (0 == strcmp(Command, "Add_Student"))
        {

            char* ID = strtok(NULL, delimiters);
            char* name = strtok(NULL, delimiters);
            char* age = strtok(NULL, delimiters);
            char* faculty = strtok(NULL, delimiters);

            PStudent pStudent = StudentCreate(name,atoi(age), atoi(ID),faculty);
            if(!ListAdd(pStudentList,pStudent))
            {
                printf("Add_Student Failed\n");
            }
            destroyStudent(pStudent); //Since StudentList holds a copy
        }
        if ( 0 == strcmp(Command, "Remove_Student") )
        {
            char* ID = strtok(NULL, delimiters);
            if(0==strcmp(ID, "All"))
            {
                ListDestroy(pStudentList);
                pStudentList=ListCreate(cloneStudent,destroyStudent,compareStudents,printStudent);
                continue;
            }
            PStudent pStudent = StudentCreate("",0, atoi(ID),"");//name, age, and faculty are irelevant
            if(!ListRemove(pStudentList,pStudent))
            {
                printf("Remove_Student Failed\n");
            }
            destroyStudent(pStudent); //Since StudentList holds a copy
        }

       /* if ( 0 == strcmp(Command, "Start_Cluster") )
        {
            char* Dim = strtok(NULL, delimiters);

            if(!(pCluster=ClusterCreate(atoi(Dim))))
            {
                printf("Start_Cluster Failed. Exiting.\n");
                exit(-1);
            }
        }
        if ( 0 == strcmp(Command, "Clear_Cluster") )
        {
            ClusterDestroy(pCluster);
            pCluster=NULL;
        }*/
        /*if ( 0 == strcmp(Command, "Add_Point") )
        {
            char* Dim = strtok(NULL, delimiters);
            int n=atoi(Dim);
            PPoint pPoint = PointCreate(n);
            char* Coordinate = strtok(NULL, delimiters);
            while(Coordinate)
            {
                if(!PointAddCoordinate(pPoint, atoi(Coordinate)))
                {
                    printf("Add Coordinate Failed.\n");
                }
                Coordinate = strtok(NULL, delimiters);
            }
            if(!ClusterAddPoint(pCluster,pPoint))
            {
                printf("Add_Point Failed.\n");
            }
            PointDestroy(pPoint);
        }*/
        if ( 0 == strcmp(Command, "Print") )
        {
            if(pStudentList)
            {
                printf("Students:\n");
                ListPrint(pStudentList);
            }
            if(test_Point)
            {
                printf("point:\n");
                PointPrint(test_Point);
            }
            /*if(pCluster)
            {
                printf("Cluster:\n");
                ClusterPrint(pCluster);
            }*/
        }
    } // while(fgets(Line, MAX_LINE_SIZE, stdin))

    /*---------command to test point files------------*/

    if(test_Point)
    {
        PointDestroy(test_Point);
    }

    /*---------end of point test------------*/

    if(pStudentList)
    {
        ListDestroy(pStudentList);
    }
    /*if(pCluster)
    {
        ClusterDestroy(pCluster);
    }*/

    return 0;
}


