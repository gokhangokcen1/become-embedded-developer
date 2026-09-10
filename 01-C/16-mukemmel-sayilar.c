#include <stdio.h>
#include <stdlib.h>

int main(){

    int bolen, number, j, i;

    printf("kaca kadar mukemmel sayilar sıralansın: ");
    scanf("%d", &number);
    for(i = 2; i<=number; i++){
        bolen = 0;
        for (j = 1; j<=i / 2; j++){
            if(i%j == 0)
                bolen += j;
        }
        if(i == bolen)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}
