#include <stdio.h>

#define V 4
#define INF 10000

void floydWarshall(int graph[][V]){
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++){
            dist[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < V; k++){
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}

void printSolution(int graph[][V]){
    printf("===== Floyd Warshall Result =====\n\n");
    for (int i = -1;i < V; i++){
        for (int j = -1; j < V; j++){
            if (i == -1){
                if (j > -1){
                    printf("%7d", j);
                } else {
                    printf("%7s", "||");
                }
            } else {
                if (j == -1 && i > -1){
                     printf("%7d", i);
                } else {
                    if (graph[i][j] == INF){
                        printf("%7s", "INF");
                    } else {
                        printf("%7d", graph[i][j]);
                    }
                }
            }
        }
        if (i == -1) printf("\n");
        printf("\n");
    }
    printf("\n===== ====================== =====");
    
}

int main()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
 
    // Print the solution
    floydWarshall(graph);
    return 0;
}