#include <stdio.h>
#include<ctype.h>
#define max_size 100
int stack[max_size];
int top = -1 ;
int max_top = -1 ;
int pop()
{
    return stack[top--] ;
}
void push(char item)
{
    stack[++top] = item-'0' ;
    if(top > max_top)
        max_top = top ;
}
int cal(int num1 , int num2 , char c)
{
    switch(c)
    {
        case'*':
            return num2*num1 ;
        case'/':
            return num2/num1 ;
        case'+':
            return num2+num1 ;
        case'-':
            return num2-num1 ;
    }
}
int main()
{
    int num ;
    scanf("%d",&num) ;
    int status = 0 ;
    for( int i = 0 ; i <= num ; i++)
    {
        char c ;
        while( (c = getchar()) != EOF)
        {
            if(c == '\n')
                break ;
            else if(isdigit(c))
            {
                push(c) ;
            }
            else if( c == '+' || c == '-' || c == '*' || c == '/')
            {
                int num1 = pop() ;
                int num2 = pop() ;
                stack[++top] = cal(num1,num2,c) ;
            }
        }
        if(status == 1)
        {
            printf("%d\n",pop());
            printf("%d\n",max_top+1);
            max_top = -1 ;
            top = -1 ;
        }
        status = 1 ;
    }
}
