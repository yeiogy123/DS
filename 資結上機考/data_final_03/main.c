#include <stdio.h>

int main()
{
    int v;
    scanf("%d",&v);
    int graph[v+1][v+1];
    for(int i = 1 ; i <= v ; i++)
    {
        for(int j = 1 ; j <= v ; j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i = 1 ; i <= v ; i++)
    {
        for(int j = 1 ; j <= v ; j++)
        {
            if(graph[i][j] == 1)
            {
                for(int vertex = 1 ; vertex <= v ; vertex++)
                {
                    if(graph[j][vertex] == 1)
                    {
                        graph[i][vertex] = 1 ;
                    }
                }
            }
        }
    }
    for(int i = 1 ; i <= v ; i++)
    {
        for(int j = 1 ; j <= v ; j++)
        {
            printf("%d",graph[i][j]);
            if(j != v)
                printf(" ");
        }
        if(i != v)
            printf("\n");
        else
            printf("\0");
    }
}
/**
 * 4
0 0 1 0
0 0 1 0
0 0 0 1
0 0 0 0
 */