#include <stdio.h>
#include<string.h>
#include<ctype.h>
#define Maxop 10000
char stack[Maxop] ;
int top = -1 ;
int priority(char token)
{
    switch(token)
    {
        case'+':case'-':
            return 1;
        case'*':case'/':
            return 2;
        default:
            return 0 ;
    }
}
void push(char token)
{
    stack[++top] = token ;
}
char pop()
{
    return stack[top--] ;
}
int main()
{
    int num = 0 ,num1  , num2 ;
    char input[Maxop] ;
        top = -1 ;
        scanf("%s",input) ;
        for(int j = 0 ; j <strlen(input) ; j++)
        {
            if (ispunct(input[j]) || isalpha(input[j]))
            {
                if (input[j] == '(')
                    push(input[j]);
                else if (input[j] == ')')
                {
                    while (stack[top] != '(')
                        printf("%c", pop());
                    pop();
                } else if (input[j] == '+' || input[j] == '-' || input[j] == '*' || input[j] == '/')
                {
                    num1 = priority(input[j]);
                    num2 = priority(stack[top]);
                    while (num1 <= num2)
                    {
                        printf("%c", pop());
                        num2 = priority(stack[top]);
                    }
                    push(input[j]);
                } else if (input[j] != '#')
                    printf("%c", input[j]);
            }
        }
        while(top != -1)
            printf("%c",pop());
}
