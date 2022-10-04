#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int graph[n+1][n+1];
    int in_degree[n+1] , out_degree[n+1];
    for(int a = 1 ; a <= n ; a++)
    {
        in_degree[a] = 0 ;
        out_degree[a] = 0 ;
    }
    int i,j ;
    for(i = 1 ; i <= n ; i ++)
    {
        for(j = 1 ; j <= n ; j++)
        {
            scanf("%d",&graph[i][j]);
            if (graph[i][j]==1)
            {
                in_degree[j]++;
                out_degree[i]++;
            }
        }
    }
    for(i = 1 ; i <= n ; i++)
    {
        printf("%d %d %d", i, in_degree[i], out_degree[i]);
        if(i != n)
            printf("\n");
        else
            printf("\0");
    }
}
/*
  5
  0 1 1 0 0
  0 0 0 1 1
  0 0 0 0 1
  0 0 0 0 1
  0 0 0 0 0
 */