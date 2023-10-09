#include <stdio.h>
#include <limits.h>
#define INF INT_MAX
#define V 4
void prtsol(int dist[][V])
{
    printf("Shortest distance matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
        if (dist[i][j] == INF)
            printf("INF\t");
        else
            printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}
void floyd(int graph[][V])
{
    int dist[V][V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                dist[i][j] = graph[i][j];
        } 
        for (int k = 0 ; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    prtsol(dist);
} 
int main() 
{
    int graph[V][V] =
    {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };
    floyd(graph);
return 0;
}