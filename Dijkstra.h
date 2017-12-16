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

void Dijkstra(AdjMGraph G, int v0, int distance[], int path[]){
/*s[]保存标记数组，意味着一个点从一个集合T到另一个集合S,
 * distance[]代表着顶点v0到其它顶点的最短距离,
 * path[]保存的是v0到某个点最短路径距离时的前一个顶点的下标
 * 为什么要这个呢？是因为我们很难一步到位的得到v0到某一顶点的最短路径，我们需要比较，
 * 比较走直线近，还是绕过一点比较近？
 * */
    int n = G.Vertices.size;
    int *s = (int *)malloc(sizeof(int)*n);//标记数组
    int minDis, i, j, u;
    /*初始化*/
    for(i = 0; i < n; i ++) {
        distance[i] = G.edge[v0][i];//从邻接矩阵中赋初值
        s[i] = 0;//T集合中的标记
        if(i != v0 && distance[i] < MaxWeight) //i ！= v0 是因为不包括v0自己，同时有通路的存在
            path[i] = v0;//前一个顶点的下标
        else
            path[i] = -1;//自己和非同路的情况
    }
    /*找到所有弧尾是v0的临接顶点，然后，path[] = v0*/

    s[v0] = 1;   //标记顶点v0已从集合T加入到集合S中

    /*在当前还未找到最短路径的顶点集中选取具有最短距离的顶点u*/
    for(i = 1; i < n; i ++) {//i = 0 已经进入S，所以从1开始
        minDis = MaxWeight;
        for(j = 0;j <= n;j ++)//这个循环是要从T中找到可连接的权值最小的顶点
            if(s[j] == 0 && distance[j] < minDis) {//s[] == 0是从T集合中查找，可链接的顶点
                u = j;//u一直保存着最小权值的下标
                minDis = distance[j];
            }
        /*当已不再存在路径时算法结束*/
        if(minDis == MaxWeight) return;
        s[u] = 1;     /*标记顶点u已从集合T加入到集合S中*/

        /*修改从v0到其它顶点的最短距离和最短路径*/
        //这里是找出u之后的下一个顶点j，通过比较确定u下一个顶点j的弧尾顶点，令path[j] = u ;
        for(j = 0; j < n; j++)
            if(s[j] == 0 && G.edge[u][j] < MaxWeight &&//比较直线路径与绕点路径的大小
               distance[u] + G.edge[u][j] < distance[j]) {
                distance[j] = distance[u] + G.edge[u][j];
                path[j] = u;
            }
    }
}

#endif //DIJKSTRA_DIJKSTRA_H
