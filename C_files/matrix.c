#include<stdio.h>

int print_seed(double *array, int size);
int print_array(double *array, int size);
int print_matrix(double*matrix, int row, int column);
void sum(double *matrix, double *matrix1, double*matrix2, int row, int column);
void schalar_multiple(double *matrix, double *matrix1, int row, int column, double schalar);

int (*ppseed)(double *array, int size);

int main(void)
{
    double a[2] = {1, 2};
    double b[1000][1000] = {{1, 2, 3}, {4, 5, 6}};
    double c[3][3] = {{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
    ppseed = print_seed;
    
    //ppseed(a, 2);
    //print_seed(a, 2);
    //print_array(a, 10000);
    print_matrix(&b[0][0], 1000, 1000);
    return 0;
}

//for文を関数ポインタにする
int print_seed(double *array, int size)
{
    int n = 0;

    for (int i = 1; i < size; i++) {
        n += printf("%f,", *(array++));
    }

    n += printf("%f]", *array);
    return n;
}
/*
//for文版
int print_array(double *array, int size)
{
    int n = 0;

    n += printf("[");

    for (int i = 0; i < size - 1; i++) {
        n += printf("%f,", *(array++));
    }

    n += printf("%f]\n", *array);

    return n;
}
*/

//関数ポインタ版
int print_array(double *array, int size)
{
    int n = 0;
    double *parray;
    parray = array;

    n += printf("[");
    n += ppseed(parray, size);
    n += printf("\n");

    return n;
}
/*
//for文版
int print_matrix(double *matrix, int row, int column)
{
    int n = 0;
    
    n += printf("[[");

    for (int i = 0; i < column - 1; i++) {
        n += printf("%f,", *(matrix++));
    }

    n += printf("%f]\n", *matrix++);
    
    for (int i = 1; i < row - 1; i++) {
        n += printf(" [");

        for (int j = 0; j < column - 1; j++) {
            n += printf("%f,", *(matrix++));
        }

        n += printf("%f]\n", *matrix++);
    }

    n += printf(" [");

    for (int i = 0; i < column - 1; i++) {
        n += printf("%f,", *(matrix++));
    }

    n += printf("%f]]\n", *matrix);

    return n;
}
*/
//関数ポインタ版
int print_matrix(double *matrix, int row, int column)
{
    int n = 0;
    double *pmatrix;
    pmatrix = matrix;

    n += printf("[[");
    n += ppseed(pmatrix, column);
    pmatrix += column;

    for (int i = 1; i < row; i++) {
        n += printf("\n [");
        n += ppseed(pmatrix, column);
        pmatrix += column;
    }

    n += printf("]\n");

    return n;
}

void sum(double *matrix, double *matrix1, double*matrix2, int row, int column)
{
    for (int i = 0; i < row*column; i++) {
        *(matrix++) = *(matrix1++) + *(matrix2++);
    }
}

void schalar_multiple(double *matrix, double *matrix1, int row, int column, double schalar);
{
        
}
