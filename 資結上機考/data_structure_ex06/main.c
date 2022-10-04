#include<stdio.h>
#include<ctype.h>
#define MAX_SIZE 10000
int input_index = 0;
char input[MAX_SIZE] ;
char output[MAX_SIZE] ;
int top_input = 0 ;
int top_output = 0 ;
void recursive() ;
int main()
{
    int a ;
    scanf("%d",&a) ;
    int time = 0 ;
    int present = 0 ;
    while(time <= a)
    {
        char c;
            while ((c = getchar())!=EOF&& c != '\n' )
            {
                input[input_index] = c ;
                input_index++ ;
            }
            while (top_input != input_index)
                recursive() ;

            for (int i = present ; i < top_output ; i++)
            {
                printf("%c", output[i]) ;
                if(i == top_output-1)
                {
                    if(time != a)
                    printf("\n") ;
                }
            }
            present = top_output ;
            time++;
    }
}
void recursive()
{

    int num = 0 ;
    int status = 0 ;
    int position ;
    while(top_input != input_index)
    {
        if(top_input == input_index)
            return ;
        if(input[top_input] == '[')
        {
            status = 1 ;
            position = top_output  ;
            top_input ++ ;
        }
        else if(input[top_input] == ']' )
        {
            if(status == 1)
            {
                num = num - 1 ;
                int position2 = top_output ;
                while (num > 0)
                {
                    int a = position ;
                    while(a < top_output)
                    {
                        output[position2] = output[a];
                        position2++;
                        a++;
                    }
                    num=num-1;
                }
                top_output = position2 ;
                top_input ++ ;
                return ;
            }
            else               //碰到其他函式的']'
                return ;
        }
        else if(status == 0)
        {
            char c = input[top_input] ;
            if (isalpha(c))
                output[top_output++] = input[top_input++];
            else if (isdigit(c))
            {
                while(isdigit(input[top_input]))
                {
                    char a = input[top_input] ;
                    int b ;
                    b = a - '0';
                    num = num * 10 + b ;
                    top_input++ ;
                }
            }
        }
        else if(status == 1 )
        {
            recursive();
        }
    }
}