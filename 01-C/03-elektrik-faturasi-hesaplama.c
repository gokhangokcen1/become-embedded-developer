#include <stdio.h>
#include <stdlib.h>

/*
 * Bir elektrik dağıtım şirketi verdikleri
 * hizmet karşılığında müşterilerinden aylık
 * olarak harcanan toplam kW saat miktarınca
 * ve belirli bir abonelik ücreti talep etmektedir.
 * Birim kW/h ücreti ve abonelik ücreti
 * her ay aylık enflasyon oranında artmaktadır.
 * Buna göre müşterinini bir aya ait ödeyeceği
 * elektrik faturasının miktarını hesaplayan program:
 * Fatura miktarı = Harcanan elektrik * birim fiyat + abone ücreti
 * */

int main(){

    float odenecekFatura, eskiBirimFiyat, yeniBirimFiyat;
    float enflasyon, eskiAboneUcreti, yeniAboneUcreti;
    int yeniOkuma, eskiOkuma,ToplamHarcananElektrik;
    printf("Enflasyon oranı: ");
    scanf("%f",&enflasyon);
    printf("Onceki aya ait birim fiyat miktarı: ");
    scanf("%f", &eskiBirimFiyat);

    printf("Onceki aya ait abonelik fiyat miktarı: ");
    scanf("%f", &eskiAboneUcreti);

    printf("Onceki aya ait okuma degeri: ");
    scanf("%d", &eskiOkuma);

    printf("Bu aya ait okuma degeri: ");
    scanf("%d", &yeniOkuma);
    ToplamHarcananElektrik=yeniOkuma-eskiOkuma;
    yeniBirimFiyat = eskiBirimFiyat*(1+enflasyon/100);
    yeniAboneUcreti=eskiAboneUcreti*(1+enflasyon/100);
    odenecekFatura=ToplamHarcananElektrik*yeniBirimFiyat+yeniAboneUcreti;
    printf("\nOdenecek fatura tutarı: %f\n\n", odenecekFatura);
    return 0;
}
