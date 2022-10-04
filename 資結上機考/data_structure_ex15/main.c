#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max_size 100

typedef struct node *list_pointer ;
typedef struct node
{
    int data ;
    list_pointer right ;
    list_pointer left ;
}Node;
list_pointer queue[max_size];
int front = -1 ;
int rear = -1 ;
list_pointer bt_insert(list_pointer btree , int num)
{
    if (btree == NULL)
    {
        btree = (list_pointer) malloc(sizeof(Node));
        btree->data = num ;
        btree->right = NULL ;
        btree->left = NULL ;
    }
    else if(num > btree->data)
        btree->right = bt_insert(btree->right , num);
    else if(num < btree->data)
        btree->left = bt_insert(btree->left , num);
    else if(num == btree->data)
    {
        if(btree->left == NULL&&btree->right == NULL)
            btree = NULL ;
        else
        {
            list_pointer temp = btree ;
            list_pointer pre = NULL ;
            while(temp->right)
            {
                temp->data = temp->right->data;
                pre = temp ;
                temp=temp->right ;
            }
            temp->right = NULL ;
            pre->right = temp->left ;
        }
    }
    return btree ;
}
void aq(list_pointer leaf)
{
    queue[++rear] = leaf ;
}
list_pointer dq()
{
    if(front != rear)
        return queue[++front] ;
    else
        return NULL ;
}
void levelorder(list_pointer btree)
{
    aq(btree) ;
    while(btree)
    {
        btree = dq();
        if (btree)
        {
            printf("%d ", btree->data);
            if (btree->left)
                aq(btree->left);
            if (btree->right)
                aq(btree->right);
        }
    }
}

int main()
{
    list_pointer btree = NULL;
    int num;
    while (scanf("%d", &num))
    {
        btree = bt_insert(btree, num);
        char c ;
        scanf("%c",&c);
        if(c == '\n')
            break ;
    }
    char a[100];
    while(scanf("%s",&a) != EOF)
    {
        num = 0 ;
        int i = 7 ;
        while (isdigit(a[i]))
        {
            num = num * 10 + (a[i] - '0');
            i++;
        }
        btree = bt_insert(btree,num) ;
    }
    levelorder(btree);
}
