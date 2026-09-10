#include <stdio.h>
#include <stdlib.h>

int main(){

    int i;
    double wheat = 1;
    double sumWheat = 0;

    for(i=1;i<=64; i++){
        printf("%d. kare için bilgine verilecek bugday sayisi: %20.0f\n", i, wheat);
        sumWheat += wheat;
        wheat *= 2;
    }
    printf("\n bilgine verilecek toplam buğday: %20.0f\n", sumWheat);
    return 0;

}
