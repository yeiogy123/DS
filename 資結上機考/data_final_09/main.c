#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50000
int compare(int x, int y)
{
    if(x > y)
        return 1 ;
    else if(x == y)
        return 0 ;
    else
        return -1 ;
}
int binary_search(int data[],int index, int target,int *steps)
{
    int front = 0 , end = index-1 , middle ;
    while(front <= end)
    {
        middle = ( front + end )/2 ;
        (*steps)++;
        switch(compare(target,data[middle]))
        {
            case -1:
                end = middle - 1;
                break;
            case 0:
                return middle ;
            case 1:
                front = middle + 1 ;
                break;
        }
    }
    return 0;
}
int main()
{
    char array[MAX],*ptr;
    int i = 0 ,target, data[MAX];
    fgets(array,MAX,stdin);
    scanf("%d",&target);
    if(array[strlen(array)-1] == '\n')
        array[strlen(array)-1] = '\0';
    ptr = strtok(array," ");
    while(ptr!= NULL)
    {
        data[i++] = atoi(ptr);
        ptr = strtok(NULL," ");
    }
    int *steps = malloc(sizeof(int));
    *steps = 0 ;
    int final = binary_search(data,i,target,steps);
    if(final)
    {
        printf("found\n");
        printf("%d steps\0",*steps);
    }
    else
    {
        printf("not found\n");
        printf("%d steps\0",*steps);
    }
}
