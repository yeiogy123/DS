#include <stdio.h>
#include <stdbool.h>
int V ;
int main()
{
    scanf("%d",&V);
    int graph[V+1][V+1],in_degree[V+1];
    bool visited[V+1] ;
    /**
     * 初始化
     */
    for(int i = 1 ; i <= V ; i++)
    {
        in_degree[i] = 0;
        visited[i] = false ;
    }
    /**
     * 掃入GRAPH跟IN_DEGREE
     */
    for(int i = 1; i <= V ; i++)
    {
        for(int j = 1 ; j <= V ; j++)
        {
            scanf("%d",&graph[i][j]);
            if(graph[i][j])
                in_degree[j] ++ ;
        }
    }
    /**
     * 找到IN_DEGREE為0的點且標註為走過
     */
    for(int v = 1 ; v <= V ; v++)
    {
        int a = 0;
        for(int j = 1 ; j <= V ; j++)
        {
            if(in_degree[j] == 0 && !visited[j])
            {
                a = j ;
                visited[j] = true ;
                break ;
            }
        }
        /**
         * 找到IN_DEGREE為0的點後
         * 輸出該點
         * 將走過的點的GRAPH變成0
         * 在更新IN_DEGREE
         */
        printf("%d", a);
        for(int j = 1 ; j <= V ; j++)
            if(graph[a][j])
            {
                in_degree[j]--;
                graph[a][j] = 0;
            }
        if(v != V)
            printf(" ");
        else
            printf("\0");
    }
}
