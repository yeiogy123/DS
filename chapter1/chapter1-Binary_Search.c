/*Binary_Search*/
#include<stdio.h>
#include<math.h>
#define max_size 100
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t)); //x>y®É­Ô
void sort(int[],int);
int binsearch(int [],int,int,int);
int compare(int,int);
void main()
{
    /*sort_selection*/
    int list[max_size],i,number;
    printf("enter the list size number\n");
    scanf("%d",&number);
    for(i=0;i<number;i++)
    {
        list[i]=rand()%1000;
        printf("%d\t",list[i]);
    }
    sort(list,number);
    for(i=0;i<number;i++)
    printf("%d\n",list[i]);
    printf("\n");
    /*binary_search*/
    int search_number,left=0,middle,right=number-1;
    while((scanf("%d",&search_number)!=EOF))
    {
            printf("%d\n",binsearch(list,search_number,left,right));
    }

}
void sort(int list[],int num)
{
    int i,j,min,temp;
    for(i=0;i<num-1;i++)
    {
        min=i;
    for(j=i+1;j<num;j++)
        if(list[min]>list[j])
        min=j;
    swap(list[i],list[min],temp);
    }
}
int compare(int x,int y)
{
    if(x>y) return 1;
    else if(x==y) return 0;
    else return -1;
}
int binsearch(int list[],int searchnum,int left,int right)
{
    int middle;
    while(left<=right)
    {
        middle=(left+right)/2;
        switch((compare(list[middle],searchnum)))
               {
                    case -1: left=middle+1;
                            break;
                    case  0: return middle;
                    case  1:right=middle-1;
               }
    }
    return -1;
}
