#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#define MAX 200
#define SWAP(X,Y,T) ((T) = (X) , (X) = (Y) , (Y) = (T) )
int main()
{
    char array[MAX] ;
    int i = 0 ,j  ;
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

    for(j = 0 ; j < i ; j++)
    {
            int min = j ,temp;
            for(int k = j+1 ; k < i ; k++)
            {
                if(data[k] < data[min] )
                    min = k ;
            }
            SWAP(data[j],data[min],temp) ;
            if(j == i-1)
                break ;
            for(int k = 0 ; k < i ; k++)
            {
                if(k > 0)
                    printf(", ");
                printf("%d",data[k]);
                if(k == i-1 && j < (i-2))
                    printf("\n");
            }
    }

}
