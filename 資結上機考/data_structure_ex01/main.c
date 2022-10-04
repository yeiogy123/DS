#include<stdio.h>
#include<stdlib.h>
#define MAX 101
typedef struct{
    int row;
    int col;
    int value;
}term;
term sparseA[MAX];
term sparseB[MAX];
term sparseD[MAX];

int **makearray(int rows, int cols){
    int **x, i;
    x = malloc(rows * sizeof(*x));

    for(i = 0; i < rows; i++){
        x[i] = malloc(cols * sizeof(**x));
    }

    return x;
}

void fillarray(int **array, int row, int col){
    int i, j;
    for(i = 0; i < row ; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &array[i][j]);
        }
    }
}


void sparse(int **origin, term t[], int row, int col){
    int i, j, cnt;
    cnt  = 1;
    t[0].value = 0;
    t[0].row = row;
    t[0].col = col;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(origin[i][j] != 0){
                t[cnt].row = i;
                t[cnt].col = j;
                t[cnt].value = origin[i][j];
                t[0].value += 1;
                cnt++;
            }
        }
    }
}

void fastTranspose(term origin[], term new[], int MAX_col){
    int rowterm[MAX_col], startingPos[MAX_col];
    int i,j, numcol = origin[0].col, numterm = origin[0].value;
    new[0].row = numcol;
    new[0].col = origin[0].row;
    new[0].value = numterm;
    if(numterm > 0){
        for(i = 0; i < numcol; i++){
            rowterm[i] = 0;
        }
        for(i = 1; i <= numterm; i++){
            rowterm[origin[i].col]++;
        }
        startingPos[0] = 1;
        for(i = 1; i < numcol; i++){
            startingPos[i] = startingPos[i - 1] + rowterm[i - 1];
        }
        printf("Starting position for each column of B:\n");
        for(i = 0; i < numcol; i++){
            printf("%d ",startingPos[i]);
        }
        printf("\n");
        for(i = 1; i <= numterm; i++){
            j = startingPos[origin[i].col]++;
            new[j].row = origin[i].col;
            new[j].col = origin[i].row;
            new[j].value = origin[i].value;
        }
    }
}

void storeSum(term d[], int *totalD, int row, int column, int *sum){
    if(*sum){
        if(*totalD < MAX){
            d[++*totalD].row = row;
            d[*totalD].col = column;
            d[*totalD].value = *sum;
            *sum = 0;
        }
    }
}

int compare(int a, int b){
    if(a < b){
        return -1;
    }
    else if(a == b){
        return 0;
    }
    else {
        return 1;
    }
}


void mult(term a[], term b[], term d[]){
    int i, j, column, totalB = b[0].value, totalD = 0;
    int rowA = a[0].row, colA = a[0].col, totalA = a[0].value;
    int colB = b[0].col;
    int rowbegin = 1, row = a[1].row, sum = 0;
    term newB[MAX];
    fastTranspose(b, newB, b[0].col);

    a[totalA + 1].row = rowA;
    newB[totalB + 1].row = colB;
    newB[totalB + 1].col = 0;
    for(i = 1; i <= totalA;){\
		column = newB[1].row;
        for(j = 1; j <= totalB + 1;){
            if(a[i].row != row){
                storeSum(d, &totalD, row, column, &sum);
                i = rowbegin;
                for(; newB[j].row == column; j++){
                    ;
                }
                column = newB[j].row;
            }
            else if(newB[j].row != column){
                storeSum(d, &totalD, row, column, &sum);
                i = rowbegin;
                column = newB[j].row;
            }
            else switch (compare(a[i].col, newB[j].col)){
                    case -1:
                        i++;
                        break;
                    case 0:
                        sum+= a[i++].value * newB[j++].value;
                        break;
                    case 1:
                        j++;
                }
        }
        for(; a[i].row == row; i++){
            ;
        }
        rowbegin = i; row = a[i].row;
    }

    d[0].row = rowA;
    d[0].col = colB;
    d[0].value = totalD;
}






int main(){
    int arow, acol, brow, bcol, i, j;
    int **A, **B;

    scanf("%d%d", &arow, &acol);
    A = makearray(arow, acol);
    fillarray(A, arow, acol);

    scanf("%d%d", &brow, &bcol);
    B = makearray(brow, bcol);
    fillarray(B, brow, bcol);

    sparse(A, sparseA, arow, acol);
    sparse(B, sparseB, brow, bcol);

    mult(sparseA, sparseB, sparseD);
    printf("A * B:\n");
    for(i = 0; i <= sparseD[0].value; i++){
        printf("%d %d %d\n", sparseD[i].row, sparseD[i].col, sparseD[i].value);
    }

    return 0;
}


