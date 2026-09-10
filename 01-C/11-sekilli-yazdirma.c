#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, j, number;
    printf("enter a number: ");
    scanf("%d", &number);

    for(i=1;i<=number;i++){
        for(j=1;j<=i;j++){
            printf("%d", i);
        }
        printf("\n");
    }

    printf("------diger------\n");
    int a,b;
    for (a=1; a<=number;a++){
        for (b=number; b>=a; b--){
            printf("%d",a);
        }
        printf("\n");
    }

    return 0;
}
