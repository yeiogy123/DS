#include<stdio.h>
#define max 100
typedef struct
{
    int row;
    int column;
    int value;
}puzzle;
int judgement_puzzle(puzzle immovable[],puzzle movable[],int box1,int box2);
int judgement_cAndr(puzzle movable[],int box2);
void up(puzzle movable[],int box2);
void down(puzzle movable[],int box2);
void shift_left(puzzle movable[],int box2);
void transs(puzzle movable[],int box2);
void shift_right(puzzle movable[],int box2);
void show (puzzle movable[],int box2);
void main()
{
puzzle immovable[max],movable[max];
int i=0,j=0,value,box1=0,input=0;
int *startim,*finishim,*startm,*finishm;
    while((input<=8)&&(scanf("%d",&value)!=EOF))
    {
        if(value>0)
        {
            immovable[box1].column=i;
            immovable[box1].row=j;
            immovable[box1].value=value;
            box1++;
        }
        i++;
        input++;
        if(i>2)
        {
            i=0;
            j++;
        }
    }
    i=0;
    j=0;
    input=0;
    int box2=0;
    while((input<=8)&&(scanf("%d",&value)!=EOF))
    {
        if(value>0)
        {
            movable[box2].column=i;
            movable[box2].row=j;
            movable[box2].value=value;
            box2++;
        }
        i++;
        input++;
        if(i>2)
        {
            i=0;
            j++;
        }
    }
    printf("immovable\n");//輸出不可移動
    show (movable,box2);
     printf("movable\n");//輸出可移動
    show (movable,box2);
    printf("right\n");
    shift_right(movable,box2);
    show (movable,box2);
}

int judgement_puzzle(puzzle immovable[],puzzle movable[],int box1,int box2)
{
    for(int j=0;j<box1;j++)
    {
        for(int i=0;i,box2;i++)
        {
            if((((immovable+j)->row)==(movable+i)->row)&&((immovable+j)->column=(movable+i)->column))
                return 1;
        }
    }
    return 0;
}
int judgement_cAndr(puzzle movable[],int box2)
{
    for(int i = 0;i < box2;i++)
    {
        if((movable+i)->row>2||(movable+i)->row<0)
        {
            return 1;
        }else if((movable+i)->column>2||(movable+i)->column<0)
        {
            return 1;
        }
    }
    return 0;
}
void up(puzzle movable[],int box2)
{
    for(int i = 0;i < box2; i++)
    {
        (movable+i)->row++;
    }
    if(judgement_cAndr(movable,box2))
        down(movable,box2);
}
void down(puzzle movable[],int box2)
{
    for(int i = 0;i < box2;i++)
    {
        (movable+i)->row--;
    }
    if(judgement_cAndr(movable,box2))
        up(movable,box2);
}
void shift_left(puzzle movable[],int box2)
{
    for(int i = 0;i < box2;i++)
    {
        (movable+i)->column--;
    }
    if(judgement_cAndr(movable,box2))
        shift_right(movable,box2);
}
void shift_right(puzzle movable[],int box2)
{
    for(int i = 0;i < box2;i++)
    {
        (movable+i)->column++;
    }
    if(judgement_cAndr(movable,box2))
        shift_left(movable,box2);
}

void transs(puzzle movable[],int box2)
{
    for(int i=0;i<box2;i++)
    {
        int temp;
        temp=(movable+i)->row;
        (movable+i)->row=(movable+i)->column;
        (movable+i)->column=2-temp;
    }
    if(judgement_cAndr(movable,box2))
    {
         for(int i=0;i<box2;i++)
        {
            int temp;
            temp=(movable+i)->column;
            (movable+i)->column=(movable+i)->row;
            (movable+i)->row=2-temp;
        }
    }
}

void show (puzzle movable[],int box2)
{
    for(int i=0;i<box2;i++)
    {
        printf("row=%d\t",(movable+i)->row);
        printf("column=%d\t",(movable+i)->column);
        printf("value=%d\n",(movable+i)->value);
    }
}
