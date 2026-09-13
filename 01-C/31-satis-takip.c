#include <stdio.h>
#include <stdlib.h>

/*
 * 1. satış temsilcisi
 *  - matematik kitabı
 *      - okula kaç adet sattı
 *      - kırtasiyeye kaç adet sattı
 *  - yazılım kitabı
 *      - okula kaç adet sattı
 *      - kırtasiyeye kaç adet sattı
 */

void readSales();
void writeSales();
int sales[3][2][2];
int i, j, k;

int main(){

    readSales();
    writeSales();


    return 0;
}


void readSales(){
    for(i=0;i<3;i++){
        printf("%d. satış temsilcisi\n", i+1);
        for(j=0;j<2;j++){
            if(j==0) printf("\tmatematik kitabı\n");
            else printf("\tyazılım kitabı\n");
            for(k=0;k<2;k++){
                if(k==0) printf("\t\tokula ");
                else printf("\t\tkirtasiyeye ");
                printf("kaç adet sattı: ");
                scanf("%d", &sales[i][j][k]);
    }
}
}}



void writeSales(){
    i=0;j=0;k=0;
    int toplamOkul = 0, toplamKirtasiye = 0, toplamMatematik = 0, toplamYazilim = 0;

    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            toplamOkul += sales[i][j][0];
            toplamKirtasiye += sales[i][j][1];
        }
        for(k=0;k<2;k++){
            toplamMatematik+=sales[i][0][k];
            toplamYazilim+=sales[i][1][k];
        }
    }
    printf("\nOkula toplam %d kitap satıldı\n",toplamOkul);
    printf("\nKırtasiyeye toplam %d kitap satıldı\n",toplamKirtasiye);
    printf("\ntoplam %d matematik kitabı satıldı\n",toplamMatematik);
    printf("\ntoplam %d yazilim kitabı satıldı\n",toplamYazilim);



}
