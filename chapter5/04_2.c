#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
typedef struct node * tree ;
typedef struct node
{
    int data ;
    int coin ;
    tree rc ;
    tree lc ;
    int total_c;
    tree p ;
    int status ;
}Node;
int max = 0 ;
int time = 0 ;
tree insert(tree root , int data , int coin , int total_c)
{
    if(root == NULL)
    {
        root = (tree)malloc(sizeof(Node));
        root->lc = root->rc = NULL ;
        root->data = data ;
        root->coin = coin ;
        root->total_c = total_c + coin ; //each of the node has the data of acceleration of coins
        root->status = false ;          //status is used for judging whether the next node can traverse while it's output
        root->p=NULL ;                  //the link to parent node
        if(max < root->total_c)
            max = root->total_c ;      //max coin
    }
    else if(root->data > data)
    {
        root->lc = insert(root->lc, data, coin, root->total_c);
        root->lc->p = root ;            //parent link
    }
    else if(root->data < data)
    {
        root->rc = insert(root->rc, data, coin, root->total_c);
        root->rc->p = root ;
    }
    return root ;
}
tree queue[MAX] ;
int front = -1 , rear = -1;
void addQ(tree root)
{
    queue[++rear] = root ;
}
tree deleteQ()
{
    if(front == rear)
        return NULL ;
    return queue[++front] ;
}
void levelorder(tree root)
{
    tree ptr ;
    if(!root)
        return ;
    addQ(root);
    for(;;)
    {
        ptr = deleteQ() ;
        if(ptr)
        {
            if(ptr->lc)
                addQ(ptr->lc) ;
            if(ptr->rc)
                addQ(ptr->rc) ; //queue
            if(ptr->total_c == max) // if it find the max equals to the acceleration of the node coin
            {
                printf("Trajectory %d:",++time);
                tree temp  = ptr ;
                while(temp->p != NULL)  //go to the root by parent link
                {
                    temp->status = true;
                    temp = temp->p;
                }
                temp->status = true ;
                tree tra = temp ;
                while(tra)
                {
                    printf(" %d", tra->data);   //print out
                    tra->status = 0 ;
                    if(tra->lc!= NULL && tra->lc->status == true)   //if the next node exists and it is true for the correct of acceleration coins road
                        tra = tra->lc ;
                    else if(tra->rc!= NULL && tra->rc->status == true)
                        tra = tra->rc ;
                    else
                        break ;
                }
                printf("\n");
            }
        }
        else
            break ;
    }
}
int main()
{
    int data , coin ;
    tree root = NULL ;

    while(scanf("%d,%d", &data , &coin) != EOF)
    {
        if(data == 00)
            break ;
        if(root == NULL)                            //create the first root
        {
            root = (tree)malloc(sizeof(Node));
            root->lc = root->rc = NULL ;
            root->data = data ;
            root->coin = coin ;
            root->total_c = coin ;
            max = root->total_c ;
            root->p = NULL ;
            root->status = false ;
        }
        else
        root = insert(root , data , coin , root->total_c ) ; //create the node
    }
    levelorder(root);
    printf("Coins: %d",max);
}
