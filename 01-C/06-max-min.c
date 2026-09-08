#include <stdio.h>
#include <stdlib.h>

int main(){

    int sayi1, sayi2, sayi3;
    printf("3 sayi gir: ");
    scanf( "%d%d%d", &sayi1, &sayi2, &sayi3);

    if(sayi1 >= sayi2 && sayi1 >= sayi3){
        printf("En büyük sayı: %d\n", sayi1);
    }else if(sayi2 >= sayi1 && sayi2 >= sayi3){
        printf("En büyük sayı: %d\n", sayi2);
    }else{
        printf("En büyük sayı: %d\n", sayi3);
    }
    return 0;

}
