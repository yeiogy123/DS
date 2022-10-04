#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX_SIZE 20
typedef struct list *list_pointer ;
typedef struct list
{
    char input[MAX_SIZE];
    list_pointer list_pointer;
}list;                                                                   //linked list
list_pointer top = NULL ;                                                   //head of linked list
char *no_punctuation(char input[]);                                      //use the string of the part of no punctuation
void traverse(char input[]);                                            //traverse thew linked list
int main()                                                                      //main function
{
    char input[MAX_SIZE];                                           //input array
    while(scanf("%s",input) != EOF)
    {
        traverse(input) ;                                           //let input go to traverse the linked list
    }
}
char  *no_punctuation(char input[])
{
    char *noPunctuation;                                                    //the pointer to char
    int i=0,j = 0;
    noPunctuation = (char *) malloc(MAX_SIZE * sizeof(char));               //malloc a space to the pointer that it can store the data without the punctuation
    while(input[i] != '\0')
    {
        if(isalpha(input[i]))                                                           //only store the part of the no punctuation
        {
            *(noPunctuation + j) = input[i] ;
            j++;
        }
        i++;
    }
    *(noPunctuation + j) = '\0';                                                //store the stop char to the pointer in the last index of char array
    return noPunctuation ;                                                  //return the no punctuation char pointer
}
void traverse(char input[])                                             //traverse the linked list
{
    int position = 2;
    list_pointer present = top;                                             //present is the list_pointer start from top
    int status = 0;                                                     //status = false
    int found = 0;                                                      //found = false
    int i = 0;
    int strl = strlen(input);
    char *input_data = no_punctuation(input);                                       //input_data is the input without punctuation
    if (top == NULL)                                                        //if there is nothing in the linked list
    {
        top = (list_pointer) malloc(sizeof(list));                          //malloc a new struct to the list in order to store the input_data
        strcpy(top->input, input_data);                                     //store the data without punctuation in top char array
        top->list_pointer = NULL;
        printf("%s ", input);
        return;                                                             //printf the ordinary input
    }
    else if (top != NULL)                                                   //if top has already existed
    {
        if (!strcmp(top->input, input_data))                                //if the input_data and the top of linked list of the char is same
        {
            while (i < strl)                                                //printf out the index number 1 with the punctuation that in input
            {
                if (ispunct(input[i]))
                    printf("%c", input[i]);
                else if (isalpha(input[i]))
                {
                    if (!found)
                    {
                        found = 1;
                        printf("1");
                    }
                }
                i++;
            }
            printf(" ");
            return;
        }
        else                                                                //if the input_data is not the same to the top char array
        {
            list_pointer current = present->list_pointer;                   //traverse to the next until null
            while (present->list_pointer != NULL)
            {
                if (!strcmp(current->input, input_data))                        //find the same
                {                                                               //print out the index number with the punctuation
                    while (i < strl)
                    {
                        if (ispunct(input[i]))
                            printf("%c", input[i]);
                        else if (isalpha(input[i]))
                        {
                            if (!found)
                            {
                                found = 1;
                                printf("%d", position);
                            }
                        }
                        i++;
                    }
                    printf(" ");
                    present->list_pointer = current->list_pointer;          //if find then free the node and break
                    free(current);
                    status = 1;                                             //status = 1 means found
                    break;                                                  //jump out the while
                }
                present = current;
                current = current->list_pointer;                            //continue traverse
                position++;
            }
            list_pointer newlist = (list_pointer) malloc(sizeof(list));         //whether the node has already free or there is no found in the linked list , still add a node into listed
            strcpy(newlist->input, input_data);
            newlist->list_pointer = top;
            top = newlist;                                                      //after linking,top = new one
            if (!status)                                                        //if no found print the ordinary input
            {
                printf("%s ", input);

            }
        }
    }
}