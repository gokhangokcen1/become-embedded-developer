#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){

    int randomNumber, guessNumber, guessCount=0, score=100;
    srand(time(NULL));
    randomNumber=(rand()%100+1);
    printf("1-100 arasında rastgele bir sayı tuttum: \n");

    while(guessNumber!=1){
        printf("tahmin sayisini gir:");
        scanf("%d", &guessNumber);
        if(guessNumber==-1) break;
        if(guessNumber < 1 || guessNumber > 100){
            printf("1-100 arası demistim\n");
            continue;
        }
        guessCount++;
        if(guessNumber == randomNumber){
            printf("Tebrikler %d seferde bildin\n", guessCount);
            break;
        }else{
            if(guessNumber>randomNumber){
                printf("daha kücük bir sayi gir\n");
                }else
                    printf("daha büyük bir sayi gir\n");
                score-=10;
        }
    }//while end

    printf("\npuanın 100 üzerinden %d\n", score < 0 ? 0: score);





    return 0;
}
