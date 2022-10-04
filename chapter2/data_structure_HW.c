#include<stdio.h>                                                                   //include stdio.h
#include<stdlib.h>                                                                  //include stdlib.h
#include<string.h>                                                                  //include string.h
#include<ctype.h>                                                                   //include ctype.h
#define max 10                                                                      //define the max number
typedef struct                                                                      //declare typedef struct
{                                                                                   //*
    int row;                                                                            //declare row is a int
    int column;                                                                         //declare column is a column
    int value;                                                                          //declare value is a value
}puzzle;                                                                            //*declare global variable puzzle which is typedef struct and it has three int variable called column, row, and value.
int judgment_puzzle(puzzle immovable[],puzzle movable[],int box1,int box2);         //declare the function judgmet_puzzle which needs three arguments returns the int value finally.
int judgment_cAndr(puzzle movable[],int box2);                                      //declare the function judgment_cAndr which needs two arguments  returns the int value finally.
void uppu(puzzle movable[],int box2);                                               //declare function uppu which needs two arguments return no any value.
void down(puzzle movable[],int box2);                                               //declare function down which needs two arguments return no any value.
void shift_left(puzzle movable[],int box2);                                         //declare function shift_right which needs two arguments return no any value.
void shift_right(puzzle movable[],int box2);                                        //declare function shift_left which needs two arguments return no any value.
void transs(puzzle movable[],int box2);                                             //declare function transs which needs two arguments return no any value.
void moving(puzzle immovable[],puzzle movable[],int box1,int box2);                 //declare function moving which needs four arguments return no any value.
void mixPuzzle(puzzle immovable[],int box1,puzzle movable[],int box2);              //declare function mixPuzzle which needs four arguments return no any value.
int main()                                                                          ///This is a main function that its return type is int value finally.
{                                                                                   //*
    int i = 0,j = 0,input = 0,box1 = 0,box2 = 0,test_time = 0,c,value,testNum;      /*declare int i,j,box1,input,box2,test_time initial number =0
                                                                                    , which i is used to represent the input sparse matrix of the column and j is used to represent the input matrix of the row
                                                                                    , which input represents the accumulation of the number of the matrix value of the test data
                                                                                    , which test_time represents the accumulation of the test data including the immovable puzzle and movable puzzle right away from zero
                                                                                    , which box1 represents the number of the input of sparse matrix that is immovable puzzle and box2 represents the number of the input of sparse matrix that is movable puzzle
                                                                                    , which testNum needs to be scanned and represents the number of the test data.*/
    scanf("%d",&testNum);                                                           //scan the testNum in order to certify the total number of the test data.
    while(test_time < testNum)                                                      ///while loop:while the situation is that test_time<testNum,it will not jump out the while loop
    {                                                                                   /*starting to store the matrix data*/
        input = 0;                                                                      //in order to store the other test data , input needs to be initialize .
        box1 = 0;                                                                       //in order to store the other test data , box1 needs to be initialize .
        box2 = 0;                                                                       //in order to store the other test data , box2 needs to be initialize .
        j = 0;                                                                          //in order to store the other test data , j needs to be initialize .
        puzzle immovable[max],movable[max];                                             //declare the data type of variable immovable and movable is puzzle with the array,which can store the data with the  number of max in the memory.
    while((input <= 8)&&((c = getchar()) != EOF))                                   ///while loop:while input <=8 and c=getchar(),whcih c!=EOF,it will not jump out the while loop.
    {                                                                               /*It's because that the input can accumulating add and is declare in the lower of the loop.The c means to get the data of "immovable" matrix value.*/
        if(isdigit(c))                                                                  //if the c is digit,return 1. While if(function())=f(1) happens, the compiler will execute the following code.
        {                                                                               /*for this judgment,if value=1 exist,it will be operated to puzzle immovable.if value=0, it won't be operated to puzzle instead it will also accumulate the i, j, and input.*/
            value = c - '0';                                                                //c represents the ascii code.In order to get the data of the matrix value, c must minus the 0's ascii code to get the value and be operated to value.*/
            if(value > 0)                                                                   //if value is >0
            {                                                                                   /*value which means the data of the matrix value exist the puzzle 1,it also needs that the matrix row,column,value be operated to puzzle immovable.*/
                immovable[box1].column = i;                                                         //i is operated to puzzle immovable[box1].column.
                immovable[box1].row = j;                                                            //j is operated to puzzle immovable[box2].row.
                immovable[box1].value = value;                                                      //value is operated to puzzle immovable[box2].value.
                box1++;                                                                             //box1=box1+1
            }                                                                                   //*
            i++;                                                                                //if value <0 , it also represent the matrix i, so i must be add 1.
            input++;                                                                            //if value <0 , it also represent the matrix data, so input must be add 1
            if(i > 2)                                                                           //if i>2 , it means that if the position of the matrix data >2
            {                                                                                   /*means the matrix change the row,as a result,j must plus while i must be operated zero*/
                i = 0;                                                                              //in order to get the more matrix data and store the position, i must be operate to 0
                j++;                                                                                //j=j+1.
            }                                                                                   //*
        }                                                                               //*
    }                                                                               ///
    i = 0;                                                                          //in order to store the other puzzle, i needs to be initialize.
    j = 0;                                                                          //in order to store the other puzzle, j needs to be initialize.
    input = 0;                                                                      //in order to store the other puzzle, input needs to be initialize.
    while((input <= 8)&&((c = getchar()) != EOF))                                   ///while loop:while input <=8 and c=getchar(),whcih c!=EOF,it will not jump out the while loop./*as the same to immovable puzzle , the difference between this one and that one is that they are stored in difference puzzle struct. */
    {                                                                                       /*It's because that the input can accumulating add and is declare in the lower of the loop.The c means to get the data of "movable" matrix value.*/
        if(isdigit(c))                                                                      //if the c is digit,return 1. While if(function())=f(1) happens, the compiler will execute the following code.//
        {                                                                                       /*for this judgment,if value=1 exist,it will be operated to puzzle immovable.if value=0, it won't be operated to puzzle instead it will also accumulate the i, j, and input.*/
            value = c-'0';                                                                      //c represents the ascii code.In order to get the data of the matrix value, c must minus the 0's ascii code to get the value and be operated to value.
            if(value > 0)                                                                         //if value is >0
            {                                                                                     /*value which means the data of the matrix value exist the puzzle 1,it also needs that the matrix row,column,value be operated to puzzle immovable.*/
                movable[box2].column = i;                                                           //i is operated to puzzle immovable[box1].column.
                movable[box2].row = j;                                                              //j is operated to puzzle immovable[box2].row.
                movable[box2].value = value;                                                        //value is operated to puzzle immovable[box2].value.
                box2++;                                                                             //box1=box1+1
            }                                                                                       //*
            i++;                                                                                //if value <0 , it also represent the matrix i, so i must be add 1.
            input++;                                                                            //if value <0 , it also represent the matrix data, so input must be add 1
            if(i > 2)                                                                           //if i>2 , it means that if the position of the matrix data >2
            {                                                                                       /*means the matrix change the row,as a result,j must plus while i must be operated zero*/
                i = 0;                                                                              //in order to get the more matrix data and store the position, i must be operate to 0
                j++;                                                                                //j=j+1.
            }                                                                                       //*
        }                                                                                       //*
    }                                                                                       ///
    moving(immovable,movable,box1,box2);                                                //use the moving function with the puzzle immovable,puzzle movable,int box1,and int box2 for total four argument.
    test_time++;                                                                        //in order to get the next data of matrix,test_time ++.
    }                                                                                   ///
    return 0;                                                                       //if the main function is no problem , return 0
}                                                                                   //*
int judgment_cAndr(puzzle movable[],int box2)                                      //judgment function body
{                                                                                   /*use for loop to verify whether the specified movable row,column of the puzzle in movable array exceed the boundary of the three by three matrix  */
    for(int i = 0;i < box2;i++)                                                         //for loop
    {                                                                                    //*
        if((movable + i)->row > 2 || (movable + i)->row < 0)                                //if any of the row of the movable in puzzle array exceed the boundary of the row
        {                                                                                   //*
            return 1;                                                                           //return 1
        }                                                                                   //*
        if((movable + i)->column > 2 || (movable + i)->column < 0)                          //else if any of the column of the movable in puzzle array in movable exceed the boundary of the column
        {                                                                                   //*
            return 1;                                                                           //return 1
        }                                                                                   //*
    }                                                                                    //*
    return 0;                                                                       //return 0
}                                                                                   ///
void uppu(puzzle movable[],int box2)                                                ///uppu function body///
{                                                                                       /*use for loop to operate the all row in movable of the puzzle in movable array*/
    for(int i = 0;i < box2; i++)                                                        //for loop
    {                                                                                       //*
        (movable + i)->row++;                                                                   //use pointer to operate the value of the row(+1)
    }                                                                                       //*
    if(judgment_cAndr(movable,box2))                                                    //use judgment_cAndr to certify whether the value of the row exceeds the row boundary
        down(movable,box2);                                                                 //if(1),then down
}                                                                                   ///
void down(puzzle movable[],int box2)                                                ///down function body///
{                                                                                       /*use for loop to operate the all row in movable of the puzzle in movable array*/
    for(int i = 0;i < box2;i++)                                                         //for loop
    {                                                                                       //*
        (movable + i)->row--;                                                                   //use pointer to operate the value of the row(-1)
    }                                                                                       //*
    if(judgment_cAndr(movable,box2))                                                    //use judgment_cAndr to certify whether the value of the row exceeds the row boundary
        uppu(movable,box2);                                                                 // if(1),then uppu
}                                                                                   ///
void shift_left(puzzle movable[],int box2)                                          ///shift_left function body///
{                                                                                       /*use for loop to operate the all column in movable of the puzzle in movable array*/
    for(int i = 0;i < box2;i++)                                                         //for loop
    {                                                                                       //*
        (movable + i)->column--;                                                                //use pointer to operate the value of the column(-1)
    }                                                                                       //*
    if(judgment_cAndr(movable,box2))                                                    //use judgment_cAndr to certify whether the value of the row exceeds the column boundary
        shift_right(movable,box2);                                                          //if(1),then shift_right
}                                                                                   ///
void shift_right(puzzle movable[],int box2)                                         ///shift_left function ///
{                                                                                       /*use for loop to operate the all column in movable of the puzzle in movable array*/
    for(int i = 0;i < box2;i++)                                                         //for loop
    {                                                                                       //*
        (movable + i)->column++;                                                                //use pointer to operate the value of the column(+1)
    }                                                                                       //*
    if(judgment_cAndr(movable,box2))                                                    //use judgment_cAndr to certify whether the value of the row exceeds the column boundary
        shift_left(movable,box2);                                                           //if(1),then shift_left
}                                                                                 ///
void transs(puzzle movable[],int box2)                                              ///transs function body///
{                                                                                       /*use for loop and declare another integer to operate the all row and column to trans angle 90*/
    for(int i = 0;i < box2;i++)                                                         //for loop
    {                                                                                       //*
        int temp;                                                                               //integer temp,which is used to be a via for change data
        temp = (movable + i)->row;                                                              //temp equal the row in movable of the puzzle in movable of the puzzle in movable array
        (movable + i)->row = (movable + i)->column;                                             //row  will equal the initial column of the same movable of the puzzle in movable array
        (movable + i)->column = 2 - temp;                                                         //column will equal 2 - temp
    }                                                                                       //*
    if(judgment_cAndr(movable,box2))                                                    //use judgment_cAndr to certify whether the value of the row and column exceed the column boundary
    {                                                                                   /*if it exceeds,than trans back to the initial */
         for(int i = 0;i < box2;i++)                                                        //for loop
        {                                                                                    //*
            int temp;                                                                           //integer temp,which is used to be a via for change data
            temp = (movable + i)->column;                                                       //temp equal the column in movable of the puzzle in movable of the puzzle in movable array
            (movable + i)->column = (movable + i)->row;                                         //column  will equal the initial row of the same movable of the puzzle in movable array
            (movable + i)->row =2 - temp;                                                       //row will equal 2 - temp
        }                                                                                   //*
    }                                                                                   //*
}                                                                                   ///
int judgment_puzzle(puzzle immovable[],puzzle movable[],int box1,int box2)                                              ///judgment_puzzle function body///
{                                                                                                                           /*use for loop to verify whether the specified movable row,column in puzzle array is correspond with the specified immovable row,column in puzzle array  */
    for(int j = 0;j < box1;j++)                                                                                             //for loop
    {                                                                                                                           //*
        for(int i = 0;i < box2;i++)                                                                                                 //for loop
        {                                                                                                                           //*
            if((((immovable + j)->row) == (movable + i)->row) && ((immovable + j)->column == (movable + i)->column))                    //if the row of movable puzzle in specified movable array equals the immovable of that and the column of movable equals the immovable of that
                return 0;                                                                                                                   //return 0
        }                                                                                                                           //*
    }                                                                                                                           //*
    return 1;                                                                                                               //return 1
}                                                                                                                       ///
void moving(puzzle immovable[],puzzle movable[],int box1,int box2)                  ///moving function body
{                                                                                   /*use the uppu, down, shift_left, shft_right, transs function to test the movable whether it can be mixed with the immovable to form the entire correct puzzle*/
    down(movable,box2);                                                                 ////use down, down, shift_left, shift_left function to initialize the movable puzzle position
    down(movable,box2);                                                                 ////as a result, each of the test data of the movable puzzle will be moved to the left with down in three by three matrix
    shift_left(movable,box2);                                                           ////to use the function twice is because that we cannot confirm whether the movable puzzle is include one, two, or even more.
    shift_left(movable,box2);                                                           ////the minimum time to move to ensure each case of the movable puzzle which will be initialized is twice time
    if (judgment_puzzle(immovable,movable,box1,box2))                                   //use the judgment_puzzle function to certify whether the movable puzzle is fixed with the immovable
        goto here;                                                                          //if(1),then goto here
    for(int t = 0;t < 4;t++)                                                           //*for loop: we can find that as the following concept of the moving, the puzzle will have a cycle with four times
        {                                                                                   ///***with two uppu, two shift_right, two down, two shift_left, two uppu, and one transs we can find out that the movable will operate with the different shape for all probable shape, which sometimes will show the shape that it had been showed up,will have a cycle for four time.
                uppu(movable,box2);                                                             //uppu
                if (judgment_puzzle(immovable,movable,box1,box2))                               //use the judgment_puzzle function to certify whether the movable puzzle is fixed with the immovable
                    goto here;                                                                      //if(1),then goto here
                uppu(movable,box2);                                                             //uppu
                if (judgment_puzzle(immovable,movable,box1,box2))                               //use the judgment_puzzle function to certify whether the movable puzzle is fixed with the immovable
                    goto here;                                                                      //if(1),then goto here
                shift_right(movable,box2);                                                      //shift_right
                if (judgment_puzzle(immovable,movable,box1,box2))                               //use the judgment_puzzle function to certify whether the movable puzzle is fixed with the immovable
                    goto here;                                                                      //if(1),then goto here
                shift_right(movable,box2);                                                      //shift_right
                if (judgment_puzzle(immovable,movable,box1,box2))                               //use the judgment_puzzle function to certify whether the movable puzzle is fixed with the immovable
                    goto here;                                                                      //if(1),then goto here
                down(movable,box2);                                                             //down
                if (judgment_puzzle(immovable,movable,box1,box2))                               //use the judgment_puzzle function to certify whether the movable puzzle is fixed with the immovable
                    goto here;                                                                      //if(1),then goto here
                down(movable,box2);                                                             //down
                if (judgment_puzzle(immovable,movable,box1,box2))                               //use the judgment_puzzle function to certify whether the movable puzzle is fixed with the immovable
                    goto here;                                                                      //if(1),then goto here
                shift_left(movable,box2);                                                       //shift_left
                if (judgment_puzzle(immovable,movable,box1,box2))                               //use the judgment_puzzle function to certify whether the movable puzzle is fixed with the immovable
                    goto here;                                                                      //if(1),then goto here
                shift_left(movable,box2);                                                       //shift_left
                if (judgment_puzzle(immovable,movable,box1,box2))                               //use the judgment_puzzle function to certify whether the movable puzzle is fixed with the immovable
                    goto here;                                                                      //if(1),then goto here
                uppu(movable,box2);                                                             //uppu
                if (judgment_puzzle(immovable,movable,box1,box2))                               //use the judgment_puzzle function to certify whether the movable puzzle is fixed with the immovable
                    goto here;                                                                      //if(1),then goto here
                uppu(movable,box2);                                                             //uppu
                if (judgment_puzzle(immovable,movable,box1,box2))                               //use the judgment_puzzle function to certify whether the movable puzzle is fixed with the immovable
                    goto here;                                                                      //if(1),then goto here
                transs(movable,box2);                                                           //transs
                if (judgment_puzzle(immovable,movable,box1,box2))                               //use the judgment_puzzle function to certify whether the movable puzzle is fixed with the immovable
                    goto here;                                                                      //if(1),then goto here
        }                                                                                   //*
        if(!judgment_puzzle(immovable,movable,box1,box2))                                   ///***with all the probable shape,it cannot be correspond to create the mix puzzle
        printf("NO\n");                                                                     ///output NO
        else                                                                               //else
        {                                                                                   //*
                here:                                                                           //here
                printf("YES\n");                                                                ///output yes
                mixPuzzle(immovable,box1,movable,box2);                                         ///mixPuzzle function
        }                                                                                   //*
}                                                                                       ///
void mixPuzzle(puzzle immovable[],int box1,puzzle movable[],int box2)               ///mixPuzzle function body
{                                                                                   //*
    int i,j ;                                                                           //declare integer i,j
    puzzle mixable[max];                                                                //declare puzzle mixable with array size of max
    for(j = 0;j < box1;j++)                                                             //for loop with box1
    {                                                                                   //*
        (mixable + j)->row = (immovable + j)->row;                                          //the row of mixable will equal the row of immovable
        (mixable + j)->column = (immovable + j)->column;                                    //the column of mixable will equal the column of immovable
        (mixable + j)->value = (immovable + j)->value;                                      //the value of mixable will equal the value of immovable
    }                                                                                   //*
    for(i = 0;i < box2;i++)                                                             //for loop with box2
    {                                                                                   //*
        (mixable + box1 + i)->row = (movable + i)->row;                                     //the row of mixable will equal the row of movable
        (mixable + box1 + i)->column = (movable + i)->column;                               //the column of mixable will equal the column of movable
        (mixable + box1 + i)->value = (movable + i)->value;                                 //the value of mixable will equal the value of movable
    }                                                                                   //*
    for(int row = 0;row < 3;row++)                                                      //for row loop
    {                                                                                   //*
        for(int column = 0;column < 3; column++)                                            //for column loop
        {                                                                                       //*
            for(int index =0;index < 9;index++)                                                     //for index loop
                if(((mixable + index)->column == column) && ((mixable + index)->row == row))            //if the column and the row of the mixable with the index of the mixable array is correspond to the matrix of the row and column which has to be output
                {                                                                                           //*
                    printf("%d",(mixable + index)->value);                                                      ///output the value
                }                                                                                           //*
            if(column == 2)                                                                             //if column ==2,it must change the line
                printf("\n");                                                                               //\n
        }                                                                                      //*
    }                                                                                   //*
}                                                                                   ///

