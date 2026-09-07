#include <stdio.h>
#include <stdlib.h>

/* 
    Kullanıcıdan 4 basamaklı bir sayı alıp bu sayının
    rakamlarını toplayan program
*/

int main(){

    int myNumber, bolum, kalan, sum;
    sum = 0;
    printf("4 basamaklı bir sayı giriniz:");
    scanf("%d", &myNumber);
    
    bolum=myNumber / 1000;
    sum += bolum;
    kalan=myNumber % 1000;
    
    bolum = kalan / 100;
    sum += bolum;
    kalan = kalan % 100;
    
    bolum = kalan / 10;
    sum += bolum;
    kalan = kalan % 10;

    sum += kalan;
    printf("Girdiğiniz sayının rakamları toplamı: %d\n", sum);

    return 0;
}
