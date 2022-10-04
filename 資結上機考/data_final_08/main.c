#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
int main()
{
    int V ;
    scanf("%d",&V) ;
    int min = INT_MIN, v1, v2, i, j, k ;
    int visited[V+1], graph[V+1][V+1] ;
    for(i = 1 ; i < V+1 ; i++)
    {
        visited[i] = false ;
        for(j = 1 ; j < V+1 ; j++)
        {
            scanf("%d",&graph[i][j]);
            if(graph[i][j])
            {
                if(min == INT_MIN || min > graph[i][j])
                {
                    min = graph[i][j] ;
                    if(i < j)
                    {
                        v1 = i ;
                        v2 = j ;
                    }
                    else
                    {
                        v1 = j ;
                        v2 = i ;
                    }
                }
            }
        }
    }
    for(i = 1 ; i < V ; i++)
    {
        printf("%d %d %d %d\n", i , v1 , v2 , min) ;
        min = INT_MIN ;
        visited[v1] = true ;
        visited[v2] = true ;
        for(j = 1 ; j < V+1 ; j++)
        {
            if (visited[j] == true)
            {
                for (k = 1; k < V + 1; k++)
                {
                    if (graph[j][k] && (!visited[k]))
                    {
                        if (min == INT_MIN || min > graph[j][k])
                        {
                            min = graph[j][k];
                            if (j < k)
                            {
                                v1 = j;
                                v2 = k;
                            } else
                            {
                                v1 = k;
                                v2 = j;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0 ;
}