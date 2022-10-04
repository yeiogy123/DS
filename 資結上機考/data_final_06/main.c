#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int n,v1,v2,flag = 1,line1=0,line2=1;
int Ki[MAX],path[MAX],total[MAX];
bool visited[MAX];
void add(int floor)
{
    if(floor <= n && floor >= 1 && visited[floor] == false)
    {
        path[line2] = floor ;
        visited[floor] = true ;
        total[line2] = total[line1] + 1;
        line2 ++;
    }
}
int main()
{
    int i;
    scanf("%d %d %d", &n, &v1, &v2);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &Ki[i]);
        visited[i] = false ;
    }
    path[0] = v1 ;//path存走過的點
    visited[v1] = true ;//標記走過
    while(path[line1] != v2)
    {
        add(path[line1]+Ki[path[line1]]);//往兩個方向走
        add(path[line1]-Ki[path[line1]]);
        line1++;//line2都會比line1大
        if(line1 >= line2)
            flag = 0;
    }
    if(flag)
        printf("%d\0",total[line1]);
    else
        printf("-1\0");
    return 0 ;
}
