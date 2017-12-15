//
// Created by antonio on 17-12-15.
//

#ifndef DIJKSTRA_ADJMGRAPH_H
#define DIJKSTRA_ADJMGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#define MaxVertices 10
#define MaxWeight 10000
#define MaxSize 100
typedef char DataType ;



//静态指针：伪指针
typedef struct {
    DataType list[MaxSize] ;
    int size ;
}SeqList;


//邻接矩阵的存储方法
typedef struct {
    SeqList Vertices ;//伪链表->存储顶点信息
    int edge[MaxVertices][MaxVertices] ;//矩阵显示边的关系
    int numOfEdges ;//有效边的个数
}AdjMGraph;

typedef struct {
    int row;			//行下标
    int col;				//列下标
    int weight;			//权值
} RowColWeight ;



void ListInitiate(SeqList *L) ;
/*
 *
 */
int ListLength(SeqList L) ;
/*
 *
 */
int ListInsert(SeqList *L, int i, DataType x) ;
/*
 *
 */
int ListGet(SeqList *L, int i, DataType *x) ;
/*
 *
 */
int ListDelete(SeqList *L, int i, DataType *x) ;
/*
 *
 */
void ListPrint(SeqList *L) ;
/*
 *
 */
void AdjInitiate(AdjMGraph *G, int n) ;
/*
 *
 */
void InsertVertex(AdjMGraph *G, DataType vertex) ;
/*
 *
 */
void InsertEdge(AdjMGraph *G, int v1, int v2, int weight) ;
/*
 *
 */
int GetFirstVex(AdjMGraph G, int v) ;
/*
 *
 */
int GetNextVex(AdjMGraph G, int v1, int v2) ;
/*
 *
 */
void DeleteEdge(AdjMGraph *G, int v1, int v2) ;
/*
 *
 */

#endif //DIJKSTRA_ADJMGRAPH_H
