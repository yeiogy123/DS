#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include <time.h>
#define max 40
typedef struct node *list_pointer ;
typedef struct node
{
    int data ;
    list_pointer right;
    list_pointer left ;
}Node;
void array_num(char a[],int array[])
{
    int i = 0;
    int j = 0 ;
    int num ;
    while(a[i]!='\n')
    {
        if (isdigit(a[i]))
        {
            num = 0 ;
            while (isdigit(a[i]))
            {
                num = num * 10 + (a[i] - '0');
                i++;
            }
            array[j] = num ;
            j++ ;
        }
        else if(a[i] == 'x')
        {
            array[j] = 0 ;
            i ++ ;
            j ++ ;
        }
        else if(a[i] == ' ')
        {
            i++ ;
        }
    }
    array[j] = '\n';
}
list_pointer insert(int arr[] , list_pointer root , int i , int n)
{
    if( i < n)
    {
        if(arr[i] > 0)
        {
            list_pointer node = (list_pointer)malloc(sizeof(Node));
            node->data = arr[i] ;
            node->left = node->right = NULL ;
            root = node;
            root->left = insert(arr, root->left, 2 * i + 1, n);
            root->right = insert(arr, root->right, 2 * i + 2, n);
        }
    }
    return root ;
}
list_pointer inorder(list_pointer root,int n , int num)
{
    n = n + root->data;
    if (root->left)
    {
        int n_left = n + root->left->data;
        if (n_left < num)
            root->left = inorder(root->left, n, num);
        else if (n_left > num)
            root->left = NULL;
        else if (n_left == num)
            root->left->right = root->left->left = NULL;
    }
    if (root->right)
    {
        int n_right = n + root->right->data;
        if (n_right < num)
            root->right = inorder(root->right, n, num);
        else if (n_right > num)
            root->right = NULL;
        else if (n_right == num)
            root->right->left = root->right->right = NULL;
    }
    if (root->right == NULL && root->left == NULL)
        return NULL;
    return root;

}
list_pointer asdd(list_pointer root)
{
        printf("%d ", root->data);
        if (root->left)
        {
                root->left = asdd(root->left);
            if (root->right == NULL && root->left == NULL)
                return NULL;
            return root;
        }
        if(root->right)
        {
                root->right = asdd(root->right);
            if (root->right == NULL && root->left == NULL)
                return NULL;
            return root;
        }
}
int main()
{

    char a[max];
    while((fgets(a, max, stdin)) != NULL)
    {
        int array[max] ;
        array_num(a,array);
        int i;
        for (i = 0; i < sizeof(array); i++)
        {
            if (array[i] == '\n')
                break;
        }
        array[i] = 0;
        list_pointer root = NULL;
        root = insert(array, root, 0, i);
        int num;
        scanf("%d", &num);
        int n = 0;
        inorder(root, n, num);
        list_pointer head;
        head = root;
        while (root)
        {
            if (head->left == NULL && head->right == NULL)
            {
                if(head->data == num)
                    printf("%d\n",head->data);
                else
                {
                    printf("Not Found");
                    printf("\n");
                }
                break;
            }
            asdd(root);
            printf("\n");
            if (root->left == NULL && root->right == NULL)
                break;
        }
        fflush(stdin);
    }
}