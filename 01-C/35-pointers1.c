#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("int: %zu\n", sizeof(int));
    printf("float: %zu\n", sizeof(float));
    printf("double: %zu\n", sizeof(double));
    printf("char: %zu\n", sizeof(char));
    printf("long double: %zu\n", sizeof(long double));


    int x=7;
    float y=3.14;
    double z = 4.23456;
    char name = 'F';


    printf("\nx variable: %d\n", x);
    printf("y variable: %f\n", y);
    printf("z variable: %f\n", z);
    printf("name variable: %c\n\n", name);

    printf("x variable address:%p\n", &x);
    printf("y variable address:%p\n", &y);
    printf("z variable address:%p\n", &z);
    printf("name variable address:%p\n", &name);

    return 0;
}
