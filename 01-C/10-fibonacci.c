#include <stdio.h>
#include <stdlib.h>

int main(){

    int first, second, third, i, number;
    first = 1;
    second = 1;
    third = 1;
    printf("enter a number:");
    scanf("%d", &number);
    printf("1 1 ");
    for(i=1;i<=number-2;i++){
        first = second;
        second = third;
        third = first + second;
        printf("%d ", third);
    }
    printf("\n\n");






    return 0;
}
