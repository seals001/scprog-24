#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int factorial(int x);

int main(void) 
{
    int order;
    double *terms;

    printf("Enter the order of the series: ");
    scanf("%d", &order);

    printf("5! is %d\n", factorial(5));

    terms = (double *)malloc(order * sizeof(double));
    for (int i = 0; i < order; i++) 
    {
        terms[i] = 1.0 / (double)factorial(i+1);
        printf("%.16lf\n", terms[i]);
       // printf("(e term for %d is %1.14lf)\n", order, terms[i]);
    }

    double e = 1.0;
    for (int i = 0; i < order; i++) 
    {
        e += terms[i];
    }

    printf("e is %1.14lf\n", e);
    free(terms);
    return 0;
}

int factorial(int x) {
    if (x<0) {
        printf("Error: Factorial of a negative number is not defined.\n");
        return -1;
    }
    else if (x == 0) {
        return 1;
    }
    else {
        return (x * factorial(x - 1));
    }
}