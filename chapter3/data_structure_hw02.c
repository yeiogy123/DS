#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define max_size 20403
typedef struct
{
    int row;
    int col;
    int hei;
    int dir;
}people;                                                                            //declare structure of the people of their data that is row, col, hei, dir.
typedef struct
{
    int vert;
    int horiz;
    int height;
}moving;                                                                            //declare the way of moving of a person
char maze[2][101][101];                                                             //declare maze that is a three dimension of char array
char mark_romeo[2][101][101];                                                       //declare mark_romeo that is a three dimension of char array that can mark the position that it had been walked by Romeo
char mark_juliet[2][101][101];                                                      //declare mark_juliet that is a three dimension of char array that can mark the position that it had been walked by Juliet
void get_maze();                                                                    //declare get_maze that get the data of maze from output
void setdata(moving move[],people romeo[],people juliet[]);                         //declare ste_data that set the all initial data including moving way, initial person's position, mark_maze of each person
void push_moving(people name[],int new_r,int new_c,int new_h,int d,int top);      //declare push_moving is that each of the moving, the past position will be pushed to the structure of the person
people pop_moving(people name[],int top);                                           //declare pop_moving is that each of the moving that has been met the 'X', it will change to the past position which pop out from the person's structure.
void path(people romeo[],people juliet[],moving move[]);                            //declare the walking function
int main()
{
    moving move[6];
    get_maze();
    get_maze();
    people romeo[max_size],juliet[max_size];
    setdata(move,romeo,juliet);
    path(romeo,juliet,move);
    system("pause");
}
void get_maze()                                                     //get_maze function,which can get the first floor and the second floor that can verify where the person states at.
{
    int y = 0,x = 0,z=0;
    char c;
    while(((c=getchar())!=EOF)&&(y<101))
    {
        if(c == '1')
            z = 0;
        else if (c == '2')
            z = 1;
        else if(c!='\n')
        {
            if(x == 101)
            {
                y++;
                x=0;
            }
            maze[z][y][x]=c;
            x++;
            if(y == 100 && x == 101)
                break;
        }
    }
}
void setdata(moving move[],people romeo[], people juliet[])//
{
    (move + 0) -> vert = 0;//up(1,0,0)
    (move + 0) -> horiz = 0;
    (move + 0) -> height = 1;

    (move + 1) -> vert = 0;//right(0,1,0)
    (move + 1) -> horiz = 1;
    (move + 1) -> height = 0;

    (move + 2) ->vert = 1;//down(0,0,1)
    (move + 2) ->horiz = 0;
    (move + 2) ->height = 0;

    (move + 3) ->vert = -1;//up(0,0,-1)
    (move + 3) ->horiz = 0;
    (move + 3) ->height = 0;

    (move + 4) ->vert = 0;//left(0,-1,0)
    (move + 4) ->horiz = -1;
    (move + 4) ->height = 0;

    (move + 5) ->vert = 0;//down(-1,0,0)
    (move + 5) ->horiz = 0;
    (move + 5) ->height = -1;

    (romeo + 0) -> hei = 0;                                 //romeo(0,1,2)
    (romeo + 0) -> col = 1;
    (romeo + 0) -> row = 1;
    (romeo + 0) -> dir = 1;                                 //d=1

    (juliet + 0) -> hei = 1;                                //juliet(1,9,8)
    (juliet + 0) -> col = 99;
    (juliet + 0) -> row = 99;
    (juliet + 0) -> dir = 4;                               //d=4
    for (int i = 0; i < 2 ;i++)                          //initial the mark array
    {
        for( int j = 0; j < 101; j++)
        {
            for(int k = 0; k < 101 ; k++)
            {
                mark_romeo[i][j][k] ='.';
                mark_juliet[i][j][k] = '.';
            }
        }
    }
}
void push_moving(people name[],int new_r,int new_c,int new_h,int d,int top)                 //push the past position to the person's structure
{
    name[top].row=new_r;
    name[top].col=new_c;
    name[top].hei=new_h;
    name[top].dir=d;
}
people pop_moving(people name[],int top)                                                    //pop out the past position from the person's structure.
{
    return name[top];
}
void path(people romeo[],people juliet[],moving move[])
{
    int romeo_r,juliet_r,romeo_c,juliet_c,romeo_h,juliet_h,romeo_d,juliet_d,new_romeo_r,new_juliet_r,new_romeo_c,new_juliet_c,new_romeo_h,new_juliet_h,round = 0;
    int romeo_top = 0,juliet_top = 0;
    bool found = false;                 //false is to judge whether Romeo and Juliet meet or not
    int meet_c,meet_r,meet_h;           //meeting position
    people get_ir,get_ij;               //get the initial position from each person's structure  ====>pop out
    get_ir = pop_moving(romeo,romeo_top);
    get_ij = pop_moving(juliet,juliet_top);
    romeo_top--;                        //when each time of popping out, the top must have to minus one
    juliet_top--;
    romeo_c = get_ir.col;               //now position and now moving direction of each person.
    romeo_r = get_ir.row;
    romeo_h = get_ir.hei;
    romeo_d = get_ir.dir;

    juliet_c = get_ij.col;
    juliet_r = get_ij.row;
    juliet_h = get_ij.hei;
    juliet_d = get_ij.dir;

    while( ((romeo_d >= 0)&&(romeo_d < 6)) && ((juliet_d < 6)&&(juliet_d >= 0)) )               //while moving direction >=0 %% <6
    {
        round++;
        printf("==Round: %d==\n",round);

        here_romeo:
        new_romeo_c = romeo_c + ((move+romeo_d) -> horiz);                                      //new position equals the past position plus the moving way.
        new_romeo_r = romeo_r + ((move+romeo_d) -> vert);
        new_romeo_h = romeo_h + ((move+romeo_d) -> height);

        if(maze[new_romeo_h][new_romeo_r][new_romeo_c] != 'X')                                 //if new position does not equals 'X'
        {
            if(mark_romeo[new_romeo_h][new_romeo_r][new_romeo_c] != 'X')                        //if the position does not have been mark /*not have been walked*/
            {
                if(maze[new_romeo_h][new_romeo_r][new_romeo_c] == '.')                          //if the position equals ','
                {
                    mark_romeo[new_romeo_h][new_romeo_r][new_romeo_c]='X';                      //mark that position
                    romeo_top++;
                    push_moving(romeo,romeo_r,romeo_c,romeo_h,romeo_d,romeo_top);               //push the past position

                    romeo_c = new_romeo_c ;                                                     //now position == new position
                    romeo_r = new_romeo_r ;
                    romeo_h = new_romeo_h ;

                    printf("Romeo: (%d,%d,%d)\n",romeo_h,romeo_c,romeo_r);                      //print new position
                    romeo_d = 1;                                                                //initial the original of the moving direction.
                }
                else if (maze[new_romeo_h][new_romeo_r][new_romeo_c] == 'o')                    //if the new position equals 'o' ====>escalator
                {
                    if(new_romeo_h==0)                                                          //if the position of romeo is at 1F
                    {
                        mark_romeo[new_romeo_h][new_romeo_r][new_romeo_c]='X';                  //mark the position of new

                        romeo_d = 0;
                        romeo_top = -1;                                                         //initialize the top of the structure cause that he cannot go down stair anymore
                        new_romeo_h = 1;
                    }
                    if(new_romeo_h==1)                                                         //now he is at 2F and he is at the 'o' second time
                    {
                        mark_romeo[new_romeo_h][new_romeo_r][new_romeo_c]='X';                  //mark the 2F of the "o" position
                        romeo_top++;
                        push_moving(romeo,romeo_r,romeo_c,romeo_h,romeo_d,romeo_top);           //push the position of the past

                        romeo_d = 1;
                        romeo_c = new_romeo_c ;                                                 //now = new position
                        romeo_r = new_romeo_r ;
                        romeo_h = new_romeo_h ;

                        printf("Romeo: (%d,%d,%d)\n",romeo_h,romeo_c,romeo_r);
                    }
                }
            }
            else                                                                                // else if the position has been marked, the moving way of direction of romeo must change
            {
                romeo_d++;
                if(romeo_d<5)
                    goto here_romeo;                                                            //if direction <5, goto here_romeo to verify the position + direction of maze whether he can walk
            }
        }
        else if(maze[new_romeo_h][new_romeo_r][new_romeo_c]=='X')                               //else if he cannot walk
        {
            mark_romeo[new_romeo_h][new_romeo_r][new_romeo_c]='X';                              //mark that he had already walked that position
            romeo_d++;
            if(romeo_d<5)
                goto here_romeo;
        }
        if(romeo_d == 5 )                                                                       //if direction==5 =>means that four way of moving way of romeo's direction have been tried by Romeo and he cannot move. => then pop out the past position to test the next direction.
        {
            people get_r;
            get_r = pop_moving(romeo,romeo_top);
            romeo_c=get_r.col;
            romeo_r=get_r.row;
            romeo_h=get_r.hei;
            romeo_d=get_r.dir;
            romeo_top--;                                                                        //each time of popping out fro the structure , top--
            printf("Romeo: (%d,%d,%d)\n",romeo_h,romeo_c,romeo_r);
            if((romeo_r == juliet_r) && (romeo_c == juliet_c) && (romeo_h == juliet_h))         //verify whether the position of romeo equals to the juliet's
            {
                found = true;
                meet_c=romeo_c;
                meet_r=romeo_r;
                meet_h=romeo_h;
            }
        }
        if((new_romeo_r == juliet_r) && (new_romeo_c == juliet_c) && (new_romeo_h == juliet_h))
            {
                found = true;
                meet_c=new_romeo_c;
                meet_r=new_romeo_r;
                meet_h=new_romeo_h;
            }
                                                                                                //juliet way   as same as romeo's
        here_juliet:
        new_juliet_c = juliet_c + ((move+juliet_d) -> horiz);
        new_juliet_r = juliet_r + ((move+juliet_d) -> vert);
        new_juliet_h = juliet_h + ((move+juliet_d) -> height);

        if(maze[new_juliet_h][new_juliet_r][new_juliet_c] != 'X')
        {
            if(mark_juliet[new_juliet_h][new_juliet_r][new_juliet_c] != 'X')
            {
                if(maze[new_juliet_h][new_juliet_r][new_juliet_c] == '.')
                {
                    mark_juliet[new_juliet_h][new_juliet_r][new_juliet_c] = 'X';
                    juliet_top++;
                    push_moving(juliet,juliet_r,juliet_c,juliet_h,juliet_d,juliet_top);

                    juliet_d = 4;
                    juliet_c = new_juliet_c ;
                    juliet_r = new_juliet_r ;
                    juliet_h = new_juliet_h ;
                    printf("Juliet: (%d,%d,%d)\n",juliet_h,juliet_c,juliet_r);

                }
                else if(maze[new_juliet_h][new_juliet_r][new_juliet_c] == 'o')
                {
                    if(new_juliet_h==1)
                    {
                        mark_juliet[new_juliet_h][new_juliet_r][new_juliet_c]='X';

                        juliet_d = 5;
                        juliet_top = -1;
                        new_juliet_h = 0;
                    }
                    if(new_juliet_h==0)
                    {
                        mark_juliet[new_juliet_h][new_juliet_r][new_juliet_c] = 'X';
                        juliet_top++;
                        push_moving(juliet,juliet_r,juliet_c,juliet_h,juliet_d,juliet_top);

                        juliet_d = 4;
                        juliet_c = new_juliet_c ;
                        juliet_r = new_juliet_r ;
                        juliet_h = new_juliet_h ;
                        printf("Juliet: (%d,%d,%d)\n",juliet_h,juliet_c,juliet_r);
                    }
                }
            }
            else
            {
                juliet_d--;
                if(juliet_d >0 )
                goto here_juliet;
            }
        }
        else if(maze[new_juliet_h][new_juliet_r][new_juliet_c]=='X')
        {
            mark_juliet[new_juliet_h][new_juliet_r][new_juliet_c]='X';
            juliet_d--;
            if(juliet_d >0 )
                goto here_juliet;
        }
        if(juliet_d == 0 )
        {
            people get_j;
            get_j = pop_moving(juliet,juliet_top);
            juliet_c = get_j.col;
            juliet_r = get_j.row;
            juliet_h = get_j.hei;
            juliet_d = get_j.dir;
            juliet_top = juliet_top-1;
            printf("Juliet: (%d,%d,%d)\n",juliet_h,juliet_c,juliet_r);
            if((new_romeo_r == juliet_r) && (new_romeo_c == juliet_c) && (new_romeo_h == juliet_h))
            {
                found = true;
                meet_c=new_romeo_c;
                meet_r=new_romeo_r;
                meet_h=new_romeo_h;
            }
        }
        if((new_romeo_r == new_juliet_r) && (new_romeo_c == new_juliet_c) && (new_romeo_h == new_juliet_h))
        {
            found = true;
            meet_c=new_romeo_c;
            meet_r=new_romeo_r;
            meet_h=new_romeo_h;
        }
        if(found)
            {
                printf("They encounter each other in (%d,%d,%d)",meet_h,meet_c,meet_r);
                break;
            }
        if((new_romeo_c == 99 && new_romeo_r == 99 && new_romeo_h == 1 )||(new_juliet_c == 1 && new_juliet_r ==1 && new_juliet_h ==0))//
        {
            printf("They do not encounter each other in this maze.");
            break;
        }
    }
}
