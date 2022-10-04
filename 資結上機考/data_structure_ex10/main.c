#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node *list_pointer ;
typedef struct node
{
    char da[10];
    list_pointer link ;
}Node;
list_pointer head = NULL;

int main()
{
    char a[20] ;
    list_pointer top = NULL ;
    int in = 0;
    while(fgets(a,20,stdin))
    {
        if(a[1] == 'u')
        {
            int i = 5;
            int index = 0;
            if (head == NULL)
            {
                head = (list_pointer) malloc(sizeof(Node));
                while (isalpha(a[i]))
                {
                    head->da[index]= a[i];
                    i++;
                    index++;
                }
                head->link = NULL;
                top = head;
                in++;
            }
            else
            {
                list_pointer temp = (list_pointer) malloc(sizeof(Node));
                while (isalpha(a[i]))
                {
                    temp->da[index] = a[i];
                    i++;
                    index++;
                }
                temp->link = top;
                top = temp;
                in++;
            }
        }
        else if(a[1] == 'o')
        {
            list_pointer temp ;
            temp = top ;
            top = temp->link ;
            temp->link = NULL ;
            free(temp);
            in-- ;
        }
    }
    printf("%d\n",in);

    while(top->link != NULL)
    {
        list_pointer tmp = top ;
        list_pointer pre;
        while(tmp->link != NULL)
        {
            pre = tmp;
            tmp = tmp->link ;
            if(tmp->link == NULL)
            {
                int i = 0 ;
                while(isalpha(tmp->da[i]))
                {
                    printf("%c",tmp->da[i]);
                    i++;
                }
                printf(", ");
                pre->link = NULL ;
                break ;
            }
        }
        if(top->link == NULL )
        {
            int i = 0;
            while(isalpha(top->da[i]))
            {
                printf("%c",top->da[i]);
                i++;
            }
            break ;
        }
    }
}
