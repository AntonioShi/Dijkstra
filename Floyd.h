//
// Created by antonio on 17-12-16.
//

#ifndef DIJKSTRA_FLOYD_H
#define DIJKSTRA_FLOYD_H

#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"

void Floyd(int cost[][MaxVertices], int n, int weight[][MaxVertices], int path[][MaxVertices]){
    //Floyd MaxVErtices为图中点的个数
    for (int i = 0; i < MaxVertices; ++i) {
        for (int j = 0; j < MaxVertices; ++j) {
            weight[i][j] = cost[i][j] ;
            path[i][j] = -1 ;
        }
    }
    //n次递推
    for (int k = 0; k < MaxVertices; ++k) {
        for (int i = 0; i < MaxVertices; ++i) {
            for (int j = 0; j < MaxVertices; ++j) {
                if (weight[i][j] < weight[i][k] + weight[k][j]){
                    weight[i][j] = weight[i][k] + weight[k][j] ;
                }
            }
        }
    }
}

#endif //DIJKSTRA_FLOYD_H
