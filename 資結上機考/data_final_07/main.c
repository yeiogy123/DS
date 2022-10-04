#include<stdio.h>
int V,start,end ;
void output(int parent[],int j)
{
    if(j == start)
    {
        printf("%d ",start+1);
        return;
    }
    output(parent,parent[j]);
    printf("%d ",j+1);
}
int choose(int distance[],int visited[])
{
    int minPos = -1, min = 999999;
    for(int i = 0 ; i < V ; i++)
    {
        if(distance[i] < min && !visited[i])
        {
            min = distance[i] ;
            minPos = i ;
        }
    }
    return minPos ;

}
void dijkstra(int graph[][V],int distance[],int visited[])
{
    int parent[V];
    int u ;
    for(int i = 0 ; i < V ; i++)
    {
        distance[i] = graph[start][i];
        parent[i] = start ;
    }
    visited[start] = 1;
    distance[start] = 0 ;
    printf("%d ",start+1);
    for(int i = 0 ; i< V-1 ; i++)
    {
        u = choose(distance,visited);
        visited[u] = 1 ;
        printf("%d ",u+1);
        for(int w = 0 ; w < V ; w++)
        {
            if(!visited[w])
            {
                if(distance[u] + graph[u][w] < distance[w])
                {
                    distance[w] = distance[u]+graph[u][w];
                    parent[w] = u ;
                }
            }
        }
    }
    printf("\n");
    output(parent,end);
}
int main()
{
    scanf("%d",&V);
    int graph[V][V],distance[V];
    int visited[V];
    for(int i = 0 ; i< V ; i++)
    {
        for(int j = 0 ; j < V ; j++)
        {
            scanf("%d",&graph[i][j]);
            if(graph[i][j] == 0 && i!=j)
                graph[i][j] = 99999;
        }
    }
    scanf("%d %d",&start,&end);
    start--;
    end--;
    for(int i = 0 ; i < V ; i++)
    {
        distance[i] = 99999;
        visited[i] = 0 ;
    }
    dijkstra(graph,distance,visited);

}
/**
7
0 3 6 9 0 0 0
0 0 2 0 4 0 0
0 0 0 0 0 7 0
0 0 0 0 0 8 0
0 0 1 0 0 0 0
0 0 0 0 0 0 0
0 0 0 5 0 0 0
2 6
 6
 0 0 0 0 0 8
 0 0 2 0 5 0
 7 0 0 3 0 4
 0 1 0 0 0 0
 9 0 0 0 0 0
 0 0 0 0 0 0
 3 2
 */