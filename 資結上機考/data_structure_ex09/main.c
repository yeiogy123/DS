#include <stdio.h>
#include<stdlib.h>
typedef struct node *list_pointer ;
typedef struct node
{
    int num ;
    list_pointer link ;
}Node;
list_pointer head = NULL ;
void output()
{
    list_pointer temp ;
    for(int i = 0 ; i < 3 ; i++)
    {
        temp = head + i ;
        while(temp != NULL)
        {
            printf("%d ",temp->num) ;
            temp = temp->link ;
        }
        if(i == 2)
            printf("\n") ;
    }
}
void add(int n , int count)
{
    list_pointer ptr = head ;
    list_pointer temp = NULL ;
    if(count == 0)
    {
        head->num = n ;
        head->link = NULL ;
    }
    else
    {
        temp = malloc(sizeof(Node));
        temp->num = n;
        temp->link = NULL;
        for (int i = 1; i < count; i++)
            ptr = ptr->link;
        ptr->link = temp;
    }
}
void cut(int count)
{
    list_pointer ptr = head ;
    list_pointer temp = NULL ;
    for(int i = 1 ; i < 3 ; i ++)
    {
        for(int j = 1 ; j < count ; j++)
            ptr = ptr->link ;
        temp = ptr->link ;
        (head+i)->num = temp->num ;
        (head+i)->link = temp ->link ;
        ptr->link = NULL ;
        ptr = (head+i) ;
    }
}
void change(int num)
{
    list_pointer front = (head+0)->link;
    list_pointer middle = (head+1)->link ;
    list_pointer end = (head+2)->link ;
    int f,m,e ;
    f = (head+0)->num ;
    m = (head+1)->num ;
    e = (head+2)->num ;
    if(num == 0)
    {
        (head + 0) ->num= m ;
        (head + 1) ->num= e ;
        (head + 2) ->num= f ;
        (head + 0) ->link = middle ;
        (head + 1) ->link = end ;
        (head + 2) ->link = front ;
    }
    else if(num == 1)
    {
        (head + 1) ->num = e ;
        (head + 1) ->link = end ;
        (head + 2) ->num = m ;
        (head + 2) ->link = middle  ;
    }
}
void invert(int num)
{
    list_pointer middle , trail ;
    middle = NULL ;
    list_pointer lead = (head+num) ;
    while(lead)
    {
        trail = middle ;
        middle = (list_pointer)malloc(sizeof(Node)) ;
        middle->num = lead->num ;
        lead = lead->link ;
        middle->link = trail ;
    }
    free(lead);
    (head+num)->num = middle->num ;
    (head+num)->link = middle->link ;
    change(num) ;
}

int main()
{
    int count = 0 ;
    int num ;
    char c ;
    head = (list_pointer)malloc(3*sizeof(Node));
    while(scanf("%d" , &num))
    {
        add(num , count++) ;
        scanf("%c",&c) ;
        if(c == '\n')
            break ;
    }
    cut(count/3) ;
    while(scanf("%d",&num)!=EOF)
    {
        invert(--num);
        output();
    }
}

