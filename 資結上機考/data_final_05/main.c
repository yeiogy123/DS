#include <stdio.h>
int v ;
int find(int i , int parent[])
{
    /**
     * 尋找接點(I的父親)
     */
    while(parent[i])
        i = parent[i];
    return i ;
}
int union1(int i , int j,int parent[])
{
    /**
     * J的父親為I
     */
    if(i!=j)
    {
        parent[j] = i;
        return 1;
    }
    return 0 ;
}
void kruskal(int graph[][v+1],int parent[])
{
    for(int i = 1 ; i <= v ; i++)
        parent[i] = 0 ;
    int edge_count = 1 ;
    while(edge_count < v )
    {
        int u1,u2;
        int min = 999999 , a = 0 , b = 0;
        /**
         * 找最小邊
         */
        for(int i = 1 ; i <= v ; i++)
        {
            for(int j = 1 ; j <= v ; j++)
            {
                if (graph[i][j] < min)
                {
                    min = graph[i][j];
                    a = i ;
                    b = j ;
                }
            }
        }
        /**
         * 尋找自己在聯集中父親的點
         * 找到後再與之交集
         * 紀錄I到J的點
         * 記錄完後 需要將該邊變成無限大
         */
        u1 = find(a,parent);
        u2 = find(b,parent);
        if(union1(u1,u2,parent))
        {
            printf("%d %d %d", a,b, min);
            edge_count++;
            if (edge_count  < v)
                printf("\n");
        }
        graph[a][b] = graph[b][a] = 999999;
    }
    printf("\0");

}
int main()
{
    scanf("%d",&v);
    int graph[v+1][v+1];
    for(int i = 1 ; i <= v ; i ++)
    {
        for(int j = 1 ; j <= v ; j ++)
        {
            scanf("%d",&graph[i][j]);
            if(graph[i][j] == 0)
                graph[i][j] = 999999;
        }
    }
    int parent[v+1];
    kruskal(graph,parent);
}
/*
 * 6
0 6 7 0 9 8
6 0 2 1 5 0
7 2 0 3 0 4
0 1 3 0 0 0
9 5 0 0 0 0
8 0 4 0 0 0
 5
 0 5 10 0 0
 5 0 0 7 3
 10 0 0 0 0
 0 7 0 0 9
0 3 0 9 0
 */

