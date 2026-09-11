#include <stdio.h>
#include <stdlib.h>

int main(){
    int numbers[7], i;

    printf("enter array numbers:");
    for(i=0;i<7;i++){
        scanf("%d", &numbers[i]);
    }
    printf("\n Original order:");
    for(i=0;i<7;i++){
        printf("%d ", numbers[i]);
    }
    printf("\n Reverse order:");
    for(i=6;i>=0;i--){
        printf("%d ", numbers[i]);
    }

    printf("\n");


    return 0;
}
