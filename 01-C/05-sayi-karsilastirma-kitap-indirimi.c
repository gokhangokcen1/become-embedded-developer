#include <stdio.h>
#include <stdlib.h>

/*
 *
 *  1- Kullanıcıdan alınan sayıları karşılaştır
 *  2- Kitap sipariş ve indirim programı yap:
 *      - miktar 60'tan fazla ise %30 indirim
 *      - miktar 30 ile 60 arasında ise %20 indirim
 *      - miktar 10 ile 30 arasında ise %12 indirim
 *      - miktar 10'dan az ise %0.1 indirim*/
int main(){
    int num1, num2;

    printf("Number 1: ");
    scanf("%d", &num1);

    printf("Number 2: ");
    scanf("%d", &num2);

    if(num1 > num2){
        printf("Number 1 > Number 2\n");
    }else if(num2 > num1){
        printf("Number2 > Number 1\n");
    }else{
        printf("Number1 = Number2\n");
    }



    int bookPrice, orderQuantity;
    float discountRate, noDiscountPrice;
    bookPrice=20;
    orderQuantity = 0;

    printf("Kaç adet kitap siparişi alınıyor: ");
    scanf("%d", &orderQuantity);

    if(orderQuantity >= 60){
        discountRate = 0.3;
    }else if(orderQuantity>= 30 && orderQuantity < 60){
        discountRate = 0.2;
    }else if(orderQuantity >= 10 && orderQuantity < 30){
        discountRate = 0.12;
    }else{
        discountRate = 0.01;
    }

    noDiscountPrice = orderQuantity * bookPrice;
    bookPrice = noDiscountPrice * (1-discountRate);
    printf("%d adet kitap için indirimli fiyat: %d\n", orderQuantity, bookPrice);
    return 0;
}
