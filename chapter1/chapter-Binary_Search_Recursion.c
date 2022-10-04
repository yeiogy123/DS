#include<stdio.h>
#include<math.h>
#define max_size 100
#define swap(x,y,t)((t)=(x),(x)=(y),(y)=(t))
int binsearch(int[] ,int,int,int);
void sort(int[],int);
int compare(int,int);
void main()
{
        int list[max_size],number,i;
        printf("enter the list number\n");
        scanf("%d\n",&number);
        for(i=0;i<number;i++)
        {
                list[i]=rand()%1000;
                printf("%d\n",list[i]);
        }
        sort(list,number);
        printf("after sorting\n");
        for(i=0;i<number;i++)
                printf("%d",list[i]);
                printf("\n");
        int search_number,left=0,right=number-1,middle;
        while(scanf("%d",&search_number)!=EOF)
        {
                printf("%d\n",binsearch_number(list,search_number,left,right));
        }
}
void sort(int list[],int number)
{
        int i,j,min,temp;
        for(i=0;i<number-1;i++)
        {
                min=i;
                for(j=i+1;j<number;j++)
                        if(list[j]<list[min])
                    min=j;
        swap(list[i],list[min],temp);
}
}
int binsearch_number(int list[],int search_num,int left,int right)
{
        int middle;
        if(left<=right)
        {
            middle = (left + right) / 2;
            switch((compare(list[middle],search_num)))
            {
                case 0:return  middle;
                case -1:return binsearch(list,search_num,middle+1,right);
                case 1:return binsearch(list,search_num,left,middle-1);
            }
        }
        return -1;
}
int compare(int x ,int y)
{
        if(x>y) return 1;
        else if(x==y) return 0;
        else return -1;
}
