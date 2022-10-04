#include <stdio.h>
#include<stdbool.h>
#define MAX_SIZE 1000
typedef struct
{
    int row ;
    int col ;
}moving ;
moving move_way[4] ;
typedef struct
{
    int row ;
    int col ;
    int dir ;
}people_position;
people_position people[MAX_SIZE] ;
int top = 0 ;
int maze[10][10], mark[10][10] ;
void initialize() ;
void push(int r, int c, int top);
people_position pop(int top);
void path() ;
int main()
{
    int c , i = 0 , j = 0;
    while((c = getchar())!=EOF)
    {
        if(c!='\n')
        {
            if(i == 10)
            {
                j++;
                i = 0;
            }
            maze[j][i] = c - '0' ;
            i++;
        }
    }
    initialize() ;
    path() ;
}
void initialize()
{
    (move_way + 0) -> row = 0 ;
    (move_way + 0) -> col = 1 ;
    (move_way + 1) -> row = 1 ;
    (move_way + 1) -> col = 0 ;
    (move_way + 2) -> row = 0 ;
    (move_way + 2) -> col = -1 ;
    (move_way + 3) -> row = -1 ;
    (move_way + 3) -> col = 0 ;
    (people + 0) -> row = 1 ;
    (people + 0) -> col = 1 ;
    (people + 0) -> dir = 0 ;
    for( int j = 0 ; j < 10 ; j++)
    {
        for(int i = 0 ; i < 10 ; i ++)
        {
            mark[j][i] = 0 ;
        }
    }
}
void push(int r, int c, int top)
{
    (people + top) -> row = r ;
    (people + top) -> col = c ;
}
people_position pop(int top)
{
    return people[top];
}
void path()
{
    int row , col , dir ,newCol , newRow  ;
    bool found = false ;
    printf("(%d,%d),",1,1);
    row = pop(top).row;
    col = pop(top).col;
    dir = pop(top).dir;
    top--;
    while (dir < 4 && !found )
    {
        newCol = col + ((move_way + dir)->col);
        newRow = row + ((move_way + dir)->row);
        if(newCol == 8 && newRow == 8)
        {
            found = true ;
            printf("(%d,%d)",newRow,newCol);
        }
        else if ((maze[newRow][newCol] == 0) && (mark[newRow][newCol] == 0))
        {
            mark[newRow][newCol] = 1;
            ++top;
            push(row,col, top);
            col = newCol;
            row = newRow;
            dir = 0;
            printf("(%d,%d),",newRow,newCol);
        }
        else
        {
            ++dir;
            if(dir ==4)
            {
                row = pop(top).row;
                col = pop(top).col;
                dir = pop(top).dir;
                top--;
                printf("(%d,%d),",row,col);
            }
        }
    }
}

