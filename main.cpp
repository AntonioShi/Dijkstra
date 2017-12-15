#include <iostream>
#include <malloc.h>
/**
 * 狄杰斯特拉算法是（源点）一个点到其余各个顶点的最短路径
 * 称之为：单源最短路径
 */

#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"
#include "Dijkstra.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    AdjMGraph G ;
    char a[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    RowColWeight rcw[] = {{0, 2, 5}, {0, 3, 30}, {1, 0, 2}, {1, 4, 8},
                          {2, 1, 15}, {2, 5, 7}, {4, 3, 4}, {5, 3, 10}, {5, 4, 18} };
    int n = 6, e = 9 ;//6个点，9条边
    int distance[6], path[6] ;
    CreatGraph(&G, a, n, rcw, e) ;
    Dijkstra(G, 0, distance, path) ;
    printf("从顶点%c到其他顶点的最短距离为：\n", G.Vertices.list[0]) ;

    for (int i = 0; i < n; ++i) {
        printf("到顶点%c的最短距离为：%d\n", G.Vertices.list[i], distance[i]) ;
    }
    printf("从顶点%c到其他各个顶点最短路径的前一顶点为:\n", G.Vertices.list[0]) ;

    for (int i = 0; i < n; ++i) {
        if (path[i] != -1)
            printf("到顶点 %c的前一项顶点是：%c\n",
                   G.Vertices.list[i], G.Vertices.list[path[i]]) ;
    }
    return 0;
}