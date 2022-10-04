#include <stdio.h>
#include<stdlib.h>
typedef struct node *list_pointer ;
typedef struct node
{
    int data ;
    list_pointer right ;
    list_pointer left ;
}Node;
void postorder(list_pointer top)
{
    if(top)
    {
        postorder(top->left);
        postorder(top->right);
        printf("%d ", top->data);
    }
}
void preorder(list_pointer top)
{
    if(top)
    {
        printf("%d ", top->data);
        preorder(top->left);
        preorder(top->right);
    }
}
void inorder(list_pointer top)
{
    if(top)
    {
        inorder(top->left);
        printf("%d ", top->data);
        inorder(top->right);
    }
}
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
    return btree ;
}
int main()
{
    list_pointer btree = NULL ;
    int num ;
    while(scanf("%d ",&num) != EOF)
        btree = bt_insert(btree,num) ;
    inorder(btree);
    printf("\n");
    postorder(btree);
    printf("\n");
    preorder(btree);
    printf("\n");
}
