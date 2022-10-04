#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 200
int find(int data[],int n)
{
    int min = data[1] - data[0] ;
    for(int i = 1 ; i < n ; i++)
    {
        if(data[i+1] - data[i] < min)
            min = data[i+1] - data[i];
    }
    return min;
}
void out_print(int final[] , int n)
{
    for(int i = 0 ; i < n+1 ; i++)
    {
        printf("%d",final[i]);
        if(i!=n)
            printf(", ");
        else
            printf("\n");
    }
}
int unSort(int final[],int n)
{
    for(int i = 0 ; i <= n-1 ; i ++)
    {
        if(final[i] > final[i+1])
            return 1 ;
    }
    return 0 ;
}
/**
 * merge
 * @param data before merge array
 * @param final after merge array
 * @param i represent initial  data1 index
 * @param m represent data1 final index and  m+1 represent data2 initial index
 * @param n represent data2 final index
 */
void merge(int data[] , int final[] , int i , int m, int n)
{
    int j, k, t;
    j = m + 1;
    k = i;

    /**
     * if value of data[i] <= data[j] then copy to the final
     * else if not , then copy the smaller to the final
     */
    while (i <= m && j <= n)
    {
        if (data[i] <= data[j])
            final[k++] = data[i++];
        else
            final[k++] = data[j++];
    }

    /**
     * after copying all of the data with i
     * if there is still have data2 , then copy it to the final
     * else if there is still have data1 whether data have or not , copy it to the final
     */
    if (i > m)
    {
        for (t = j; t <= n; t++)
            final[t] = data[t];
    }
    else
    {
        for(t = i ; t <= m ; t++)
            final[k+t-i] = data[t] ;
    }
}
/**
 *
 * @param data
 * @param final
 * @param n means the number of value in the section
 * @param s means the size of the section
 * n-2*s+1 means the 'number of section'
 * 2*s means the width of section , which means the distance of this section to next section
 * i+s-1 means merge from data1 when index == 1 util index == i+s-1 ,which also means the least index of data1
 *
 */
void mergePass(int data[] , int final[] , int n , int s)
{
    int i , j ;
    for( i = 0 ; i < n-2*s+1 ; i+= 2*s)
        merge(data,final,i,i+s-1,i+2*s-1);
    if(i+s-1<n)
        merge(data,final,i,i+s-1,n);
    else
    {
        for( j = i ; j <= n ; j++)
            final[j] = data[j] ;
    }
}
/**
 * s means the widths
 * @param data data from 0 to n with to data
 * @param n index
 */
void mergesort(int data[], int n)
{
    int s = 1 ;
    int final[MAX];
    /**
     * USE the algorithm to let data merge to final then using final to merge data util the discrimination is not correct
     */
    while(s <= n)
    {
        mergePass(data,final,n,s) ;
        s*=2 ;
        out_print(final,n);
        if(!unSort(final,n))
        {
            printf("Minimum gap: %d",find(final,n));
            break;
        }
        mergePass(final,data,n,s);
        s*=2 ;
        out_print(data,n);
        if(!unSort(data,n))
        {
            printf("Minimum gap: %d",find(data,n));
            break ;
        }
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
    mergesort(data,i-1);
    return 0;
}
