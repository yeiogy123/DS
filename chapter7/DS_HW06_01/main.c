#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX 200
#define SWAP(X,Y,T) ((T) = (X) , (X) = (Y) , (Y) = (T) )
void Array_print(int len ,int data[])
{
    for(int i = 0 ; i < len ; i++)
    {
        printf("%d", data[i]);
        if(i!=len-1)
            printf(", ");
    }
}
int unsort(int data[],int len)
{
    for(int i = 0 ; i < len-1 ; i++)
    {
        if(data[i] < data[i-1])
            return 1;
    }
    return 0 ;
}

void quick_sort(int *data,int front , int end , int len )
{
    int pivot = data[front],i,j ;
    int temp;
    if(front<end)
    {
        i = front ;
        j = end + 1;
        do{
            do {i++;}
            while(data[i]<pivot);
            do {j--;}
            while(data[j]>pivot);
            if(i < j)
                SWAP(data[i],data[j],temp);
        }while(i < j) ;
        SWAP(data[front],data[j],temp);
        Array_print(len,data);
        if(unsort(data,len))
            printf("\n");
        quick_sort(data,front,j-1,len);
        quick_sort(data,j+1,end,len);
    }
}
int main()
{
    char array[MAX] ;
    int i = 0   ;
    fgets(array,MAX,stdin);
    char *ptr = array ;
    int data[MAX];
    while(*ptr != '\n')
    {
        if(isdigit(*ptr))
        {
            data[i++]=atoi(ptr);
            while(isdigit(*ptr))
            {
                ptr++;
            }
        }
        else
            ptr++;
    }
    quick_sort(data,0,(i-1),i);
    return 0;
}
/**
*43, 10, 84, 37, 95, 71, 29, 57, 62
 */