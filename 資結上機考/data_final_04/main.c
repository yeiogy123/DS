#include <stdio.h>
#define MAX 128
#define SWAP(x,y,t)((t)=(x), (x) = (y), (y)=(t))
void array_print(int array[],int index)
{
    for(int i = 0; i < index; i++)
    {
        printf("%d",array[i]);
        if(i != index-1)
            printf(" ");
    }
}
int sort(int array[],int index)
{
    for(int i = 0 ; i < index ; i++)
    {
        if(i == index-1)
            return 1 ;
        if(array[i] > array[i+1])
            return 0 ;
    }
}
void quick_sort(int array[], int front, int end, int index)
{
    int i = front, j = end+1, pivot = array[front],t ;
    if(front < end)
    {
        do
        {
            do{i++;}
            while(array[i] < pivot);
            do{j--;}
            while(array[j] > pivot);
            if(i < j)
            {
                SWAP(array[i], array[j], t);
                if(!sort(array,index))
                {
                    array_print(array,index);
                    printf("\n");
                }
            }
        }while(i < j);
        if(pivot > array[j])
        {
            SWAP(array[front], array[j], t);
            if (!sort(array, index))
            {
                array_print(array, index);
                printf("\n");
            }
        }
        quick_sort(array, front, j - 1, index);
        quick_sort(array, j + 1, end, index);
    }
}
int main()
{
    int index = 0 ;
    int array[MAX] ;
    while(scanf("%d",&array[index])!=EOF)
        index++ ;
    quick_sort(array,0,index-1,index);
    array_print(array,index);
    printf("\0");
    return 0 ;
}
