#include <stdio.h>
#include <stdlib.h>

/*
 * 1- girilen sayının onlar ve birler basamağını bulan program
 * 2- girilen dört sayının aritmetik ortalamasını bulan program.
 *
 * */
int main(){

    int myNumber, first, second;

    printf("Pozitif bir sayı giriniz:");
    scanf("%d", &myNumber);

    first = myNumber % 10;
    printf("girilen sayının birler basamagi: %d\n",first);
    second = (myNumber%100)/10;
    printf("girilen sayının onlar basamagi: %d\n",second);


    float a,b,c,d, ortalama;
    printf("Pozitif 4 sayı yazınız:");
    scanf("%f%f%f%f",&a,&b,&c,&d),
    ortalama = ( a + b + c + d) / 4;
    printf("aritmetik ortalaması = %f\n",ortalama);

    return 0;
}
