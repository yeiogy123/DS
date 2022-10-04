#include <stdio.h>
#include <stdbool.h>
#define min(x,y) ((x)<(y) ? (x) : (y))
int V,num = 0 ;
void cal(int graph[][V+1], int u , int v, int dfn[] , int low[],bool atp[],int root)
{
    dfn[u] = low[u] = num++ ;
    int w,children = 0 ;
    for(int i = 1; i <= V ; i++)
    {
        if (graph[u][i] == 1)
        {
            w = i ;
            if (dfn[w] < 0)
            {
                children++;
                cal(graph, w, u, dfn, low,atp,root);

                low[u] = min(low[u], low[w]);

                if(u == root && children > 1)
                    atp[u] = true ;

                if(u != root && low[w] >= dfn[u])
                    atp[u] = true ;
            }
            else if (w != v)
                low[u] = min(low[u], dfn[w]);
        }
    }

}
int main()
{
    int root ;
    scanf("%d",&root);
    scanf("%d",&V);
    int graph[V+1][V+1],dfn[V+1],low[V+1];
    bool atp[V+1];
    for(int i = 1 ;i <= V ; i++)
        for(int j = 1 ; j <= V ; j++)
            scanf("%d",&graph[i][j]);

    for(int i = 1 ; i <= V ; i++)
    {
        dfn[i] = low[i] = -1 ;
        atp[i] = false ;
    }

    cal(graph,root,-1,dfn,low,atp,root);

    for(int i = 1 ; i <= V ; i++)
        printf("%d ",dfn[i]);
    printf("\n");

    for(int i = 1 ; i <= V ; i++)
        printf("%d ",low[i]);
    printf("\n");

    for(int i = 1 ; i <= V ; i++)
        if(atp[i])
            printf("%d ", i);
    printf("\0");
}
/**
4
10
0 1 0 0 0 0 0 0 0 0
1 0 1 1 0 0 0 0 0 0
0 1 0 0 1 0 0 0 0 0
0 1 0 0 1 1 0 0 0 0
0 0 1 1 0 0 0 0 0 0
0 0 0 1 0 0 1 1 0 0
0 0 0 0 0 1 0 1 0 0
0 0 0 0 0 1 1 0 1 1
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1 0 0
 */