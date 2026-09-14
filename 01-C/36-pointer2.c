#include <stdio.h>
#include <stdlib.h>

int main(){
    int x=7;
    int* ptr=&x; //burada int* ifadesi şu anlama gelmektedir: ptr pointerı içerisinde integer barındıran bir değişkeni tutuyor.
    printf("x: %d\n", x);
    printf("x variable address: %p\n", &x);
    printf("x variable address: %p\n", ptr);
    printf("ptr variable address: %p\n", &ptr);
    printf("x variable: %d\n", *ptr);

    *ptr = 19;
    printf("new x variable: %d\n",x);

    double a=3.14;
    double* y= &a;
    double* z=&a;

    printf("y: %f\n", *y);
    printf("z: %f\n", *z);
    *y = 21.19;
    printf("z: %f\n", *z);

    char name='f';
    char* ptr2=&name;
    printf("Pointer: %p\n", ptr2);
    ptr2++;
    printf("Pointer: %p\n", ptr2);
    ptr2--;
    printf("Pointer: %p\n", ptr2);



    return 0;
}
