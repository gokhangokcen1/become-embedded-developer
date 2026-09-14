#include <stdio.h>
#include <stdlib.h>

double getSquare(double *ptr);

int main(){
    double number, result;

    printf("enter a number: ");
    scanf("%lf", &number);

    result = getSquare(&number);

    printf("Square of number: %.2f\n\n", result);

    return 0;
}

double getSquare(double *ptr){
    return *ptr * *ptr;
}
