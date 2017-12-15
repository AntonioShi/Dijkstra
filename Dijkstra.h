//
// Created by antonio on 17-12-15.
//

#ifndef DIJKSTRA_DIJKSTRA_H
#define DIJKSTRA_DIJKSTRA_H

#include "AdjMGraph.h"

//void Dijistra(AdjMGraph G, int v, int distance[], int path[]){
//    //带权图G从下标v顶点到其他各个顶点的最短距离distance和最短路径下标path
//    int n = G.Vertices.size ;
//    int *s = (int *)malloc(sizeof(int) * n) ;
//    int minDis, i, j, u ;
//    //初始化
//    for (int i = 0; i < n; ++i) {
//        distance[i] = G.edge[v][i] ;
//        s[i] = 0 ;
//        if (i != v && distance[i] < MaxWeight)
//            path[i] = v ;
//        else
//            path[i] = -1 ;
//    }
//    s[v] = 1 ;//标记顶点v已从集合T加入到集合S中
//
//    //在当前还没找到最短距离的顶点集中选取具有最短距离的顶点u
//    for (int i = 1; i < n; ++i) {
//        minDis = MaxWeight ;
//        for (int j = 0; j < n; ++j) {
//            if (s[j] == 0 && distance[j] < minDis){
//                u = j ;
//                minDis = distance[j] ;
//            }
//        }
//        //当已不再存在路径时，算法结束。此语句对非连通图是必需的
//        if (minDis == MaxWeight) return;
//        s[i] = 1 ;
//        //修改从v到其他各个顶点的最短距离和最短路径
//        for (int j = 0; j < n; ++j) {
//            if (s[j] == 0 && G.edge[u][j] < MaxWeight
//                    && distance[u] + G.edge[u][j] < distance[j]){
//                //顶点v经顶点u到其他顶点的最短距离和最短路径
//                distance[j] = distance[u] + G.edge[u][j] ;
//                path[j] = u ;
//            }
//        }
//    }
//}

void Dijkstra(AdjMGraph G, int v0, int distance[], int path[])
/*带权图G从下标v0顶点到其它顶点的最短距离distance*/
/*和最短路径下标path*/
{
    int n = G.Vertices.size;
    int *s = (int *)malloc(sizeof(int)*n);
    int minDis, i, j, u;
    /*初始化*/
    for(i = 0; i < n; i ++)
    {
        distance[i] = G.edge[v0][i];
        s[i] = 0;
        if(i != v0 && distance[i] < MaxWeight) path[i] = v0;
        else path[i] = -1;
    }
    s[v0] = 1;   //标记顶点v0已从集合T加入到集合S中

    /*在当前还未找到最短路径的顶点集中选取具有最短距离的顶点u*/
    for(i = 1; i < n; i ++)
    {
        minDis = MaxWeight;
        for(j = 0;j <= n;j ++)
            if(s[j] == 0 && distance[j] < minDis)
            {
                u = j;
                minDis = distance[j];
            }
        /*当已不再存在路径时算法结束*/
        if(minDis == MaxWeight) return;
        s[u] = 1;     /*标记顶点u已从集合T加入到集合S中*/

        /*修改从v0到其它顶点的最短距离和最短路径*/
        for(j = 0; j < n; j++)
            if(s[j] == 0 && G.edge[u][j] < MaxWeight &&
               distance[u] + G.edge[u][j] < distance[j])
            {
                distance[j] = distance[u] + G.edge[u][j];
                path[j] = u;
            }
    }
}

#endif //DIJKSTRA_DIJKSTRA_H
