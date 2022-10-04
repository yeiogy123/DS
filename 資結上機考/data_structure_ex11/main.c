#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_size 100
typedef struct node * list_pointer ;
typedef struct node
{
    char name[max_size] ;
    list_pointer link ;
}Node;
list_pointer head  = NULL ;
void add(char name[])
{
    list_pointer tmp = head ;
    if(head == NULL)
    {
        head = (list_pointer)malloc(sizeof(Node)) ;
        strcpy(head->name,name);
        head->link = head ;
    }
    else
    {
        list_pointer new = (list_pointer) malloc(sizeof(Node));
        strcpy(new->name , name);
        new->link = tmp->link ;
        tmp->link = new ;
        head = new ;
    }
}
void del(int n )
{
    list_pointer tmp =head ;
    list_pointer tem ;
    while(tmp->link != tmp)
    {
        for (int i = 0; i < n-1; i++)
            tmp = tmp->link;
        tem = tmp->link ;
        printf("%s is killed.\n",tem->name);
        tmp->link = tem->link ;
        tem->link = NULL ;
        free(tem);
        tmp = tmp->link ;
    }
    head = tmp ;

}
int main()
{
    char data[max_size] ;
    char c ;
    int i = 0;
    while((c = getchar()) != EOF)
    {
        if(c != ' ')
        {
            if (c == ',' || c == '\n')
            {
                data[i] = '\0';
                add(data);
                i = 0;
                if (c == '\n')
                    break;
            } else
                data[i++] = c;
        }
    }
    head = head->link ;
    int n ;
    scanf("%d",&n);
    del(n);
    printf("%s is survived.\n",head->name);
}
