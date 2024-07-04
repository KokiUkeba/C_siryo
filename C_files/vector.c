#include<stdio.h>
#include<math.h>

void sum(int, double*, double*, double*);
void scalar_multiple(double, int, double*);
double inner_product(int, double*, double*);
double norm(int, double*);

int main(void)
{
    double a[1000];
    double b[1000];
    
    for (int i = 0; i < 1000; i++) {
        a[i] = i;
        b[i] = i;
    }

    double c[100];
    sum(100, c, a, b);

    for (int i = 0; i < 1000; i++) {
        printf("c[%d]=%f\n", i, c[i]);
    }
    
    printf("-----------------\n");
    scalar_multiple(2, 1000, c);

    for (int i = 0; i < 1000; i++) {
        printf("c[%d]=%f\n", i, c[i]);
    }

    printf("-----------------\n");
    double ans;
    ans = inner_product(1000, a, b);
    printf("ans=%f\n", ans);
    
    printf("-----------------\n");
    ans = norm(1000, a);
    printf("ans=%f\n", ans);
    
    return 0;
}

void sum(int size, double *ans, double *array1, double *array2)
{
    for (int i = 0; i < size; i++) {
        *(ans++) = *(array1++) + *(array2++); 
    }
}

void scalar_multiple(double scalar, int size, double *array)
{
    for (int i = 0; i < size; i++) {
        *(array++)*=scalar;
    }   
}

double inner_product(int size, double *array1, double *array2)
{
    double answer = 0;

    for (int i = 0; i < size; i++) {
        answer += *(array1++) * *(array2++);   
    }

    return answer;
}

double norm(int size, double *array1)
{
    double answer = 0;

    for (int i = 0; i < size; i++) {
        answer += *array1 * *(array1++);
    }
    
    return sqrt(answer);
}
