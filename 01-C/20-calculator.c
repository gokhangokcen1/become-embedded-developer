#include <stdio.h>
#include <stdlib.h>
#include "myMath.h"


int main(){
    int choose=0, x, y;
    menu();
    printf("\nChoose a number (1-5):");
    scanf("%d", &choose);
    printf("\n");

    switch(choose){
        case 1: printf("enter 2 number:");
                scanf("%d%d", &x, &y);
                printf("min: %d\n", min(x,y));
                break;
        case 2: printf("enter 2 number:");
                scanf("%d%d", &x, &y);
                printf("max: %d\n", max(x,y));
                break;
        case 3: printf("enter a number:");
                scanf("%d", &x);
                printf("square: %d\n", square(x));
                break;
        case 4: printf("enter a number:");
                scanf("%d", &x);
                printf("cube: %d\n", cube(x));
                break;
        case 5: printf("enter a number:");
                scanf("%d", &x);
                printf("absolute: %d\n", absolute(x));
                break;
    }
    return 0;
}


void menu() {
    printf("\n");
    printf("**********\n");
    printf("*  MENU  *\n");
    printf("**********\n");
    printf("1-Min\n");
    printf("2-Max\n");
    printf("3-Kare al\n");
    printf("4-Kup al\n");
    printf("5-Mutlak deger\n");
}

int min(int x, int y){
    if(x <= y)
        return x;
    else
        return y;
}

int max(int x, int y){
    if ( x >= y )
        return x;
    else
        return y;
}

int square(int x){
    return x * x;
}

int cube(int x){
    return x * x * x;
}

int absolute(int x){
    if (x<0)
        return x * (-1);
    else
        return x;
}
