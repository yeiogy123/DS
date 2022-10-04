#include <stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct node * list_pointer ;
typedef struct node
{
  int data ;
  list_pointer left_c ;
  list_pointer right_c ;
}Node;
list_pointer queue[MAX] ;
int front = -1 , rear = -1;
void addQ(list_pointer root)
{
    queue[++rear] = root ;
}
list_pointer deleteQ()
{
    if(front == rear)
        return NULL ;
    return queue[++front] ;
}
list_pointer insert(list_pointer root ,int data )
{
    if(root == NULL)                                                                    //if there is no root in the tree
    {
        root = (list_pointer) malloc(sizeof(Node)) ;
        root->data = data ;
        root->left_c = root->right_c = NULL ;
    }
    else if(root->data > data)                                                          //if the data < root data
        root->left_c = insert(root->left_c ,data ) ;
    else if(root->data < data)                                                          //if the data > root data
        root->right_c = insert(root->right_c ,data );
    return root ;
}
void inorder(list_pointer root)                                             //inorder output with recursive
{
    if(root)
    {
        inorder(root->left_c) ;
        printf("% d",root->data) ;
        inorder(root->right_c) ;
    }
}
void levelorder(list_pointer root)                                          //level order output with queue
{
    list_pointer ptr ;
    if(!root)
        return ;
    addQ(root);
    for(;;)
    {
        ptr = deleteQ() ;
        if(ptr)
        {
            if(front != 0)
                printf(" ");
            printf("%d",ptr->data) ;
            if(ptr->left_c)
                addQ(ptr->left_c) ;
            if(ptr->right_c)
                addQ(ptr->right_c) ;
        }
        else
            break ;
    }
}
int main()
{
    int data ;
    list_pointer root = NULL ;
    while(scanf("%d",&data)!=EOF)
    {
        if(data == 00)
            break ;
        root = insert(root ,data ) ;
    }
    printf("Infixorder:");
    inorder(root) ;
    printf("\n");
    printf("Levelorder: ");
    levelorder(root) ;
}
