#include <stdio.h>
#include <stdlib.h>

/*
 * Kapalı bir kaptaki gazın basıncını
 * hesaplayan program
    basınç = (mol sayısı * R sabiti * sıcaklık) / hacim
*/

int main(void){

    float pressure, constantR;
    int numberOfMoles, volume, heat;
    constantR = 0.82;

    printf("Kabin hacmini giriniz:");
    scanf("%d", &volume);
    printf("Kaptaki mol sayisini giriniz:");
    scanf("%d", &numberOfMoles);
    printf("Ortam sicakligini giriniz:");
    scanf("%d", &heat);

    pressure = (numberOfMoles*constantR*heat)/volume;
    printf("Pressure: %f\n", pressure);
    return 0;
}
