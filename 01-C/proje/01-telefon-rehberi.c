#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "menu.h"
#include "phoneadd.h"
#include "phonelist.h"
#include "phonesearch.h"



int main(){

    int choice=0;
    char searchName[20];
    int searchResult=0;
    menu();

    do{
        printf("\n\n seçiminizi giriniz:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(phoneAdd() == 0){
                    printf("\n telefon numarası basarıyla eklendi\n");
                }else{
                    printf("\n telefon numarası eklenirken hata oldu\n");
                }

                break;
            case 2:
                if(phoneList() == 0){
                    printf("\n Telefon numaraları başarılı bir şekilde listelendi\n");
                }else{
                    printf("\n Telefon numaraları lsitelenirken hata oluştu.\n");
                }
                    break;
            case 3: printf("\nAranacak ismi giriniz:");
                    scanf("%s", searchName);
                    searchResult = phoneSearch(searchName);
                    if(searchResult == 0){
                        printf("\nAranılan kayıt bulunamadı\n");
                    }else{
                        printf("\nToplam %d kayıt bulundu\n", searchResult);
                    }
                    break;
            case 4: printf("\n Cikis yaptınız. Hoşça kalın\n");
                    break;
            default:printf("lütfen 1-4 arası gir\n");

        }
    }while(choice != 4);
    return 0;


    return 0;
}
