#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node *list_pointer ;
typedef struct node
{
    int num ;
    int exp ;
    list_pointer next ;
    list_pointer pre ;
}Node;
list_pointer insert(list_pointer head , int num , int exp)
{
    if(num!=0)
    {
        list_pointer temp = head;
        if (head == NULL)
        {
            head = (list_pointer) malloc(sizeof(Node));
            head->num = num;
            head->exp = exp;
            head->next = head->pre = NULL;
        } else
        {
            while (temp->exp > exp)
            {
                if (temp->next == NULL)
                {
                    list_pointer new = (list_pointer) malloc(sizeof(Node));
                    new->num = num;
                    new->exp = exp;
                    new->next = NULL;
                    new->pre = temp;
                    temp->next = new;
                    break;
                }
                temp = temp->next;
            }
            if (temp->exp == exp)
            {
                temp->num = temp->num + num;
                if (temp->num == 0)
                {
                    temp->pre->next = temp->next;
                    free(temp);
                }
            } else if (temp->exp < exp)
            {
                list_pointer new = (list_pointer) malloc(sizeof(Node));
                new->num = num;
                new->exp = exp;
                new->pre = new->next = NULL;
                if (temp->pre == NULL)
                {
                    new->next = temp;
                    temp->pre = new;
                    head = new;
                } else
                {
                    new->next = temp;
                    new->pre = temp->pre;
                    temp->pre->next = new;
                    temp->pre = new;
                }
            }
        }
    }
    return head;
}
void print_head(list_pointer head)
{
    while(head->next != NULL)
    {
        printf("%d %d\n",head->num , head->exp );
        head = head->next ;
    }
    printf("%d %d",head->num , head->exp) ;
}
int main()
{
    char input[100]  ;
    int num ,exp;
    list_pointer head = NULL ;
    scanf("%s",input);
    while(strcmp(input,"next") != 0)
    {
        num = atoi(input) ;
        scanf("%s",input) ;
        exp = atoi(input) ;
        head = insert(head , num , exp ) ;
        scanf("%s",input) ;
    }
    scanf("%s",input) ;
    while(strcmp(input,"end") != 0)
    {
        num = atoi(input) ;
        scanf("%s",input) ;
        exp = atoi(input) ;
        head = insert(head , num , exp ) ;
        scanf("%s",input) ;
    }
    print_head(head) ;

}
