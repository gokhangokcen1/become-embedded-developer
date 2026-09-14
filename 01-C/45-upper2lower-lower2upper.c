#include <stdio.h>
#include <stdlib.h>

void upperToLower(char*);
void lowerToUpper(char*);

int main(){

    char message[100];
    int choice;
    puts("Bir secim yapınız");
    puts("1- büyük harften kücük harfe cevir");
    puts("2- kucuk harften buyuk harfe cevir");
    scanf("%d", &choice);
    getchar(); //scanf'ten sonra fgets kullanamadığımız için bunu yazıyoruz
    switch(choice){
        case 1: puts("Büyük harflerden olusan bir cümle gir");
                fgets(message, sizeof(message), stdin);
                upperToLower(message);
                break;
        case 2: puts("Küçük harflerden oluşan bir cümle gir");
                fgets(message, sizeof(message), stdin);
                lowerToUpper(message);
                break;
        default: puts("Yanlis secim");
    }

    printf("\n\n");

    return 0;
}

void upperToLower(char* ptr){
    for(;*ptr!='\0';ptr++){
        if(*ptr>='A' && *ptr<='Z'){
            putchar(*ptr+32);
        }else{
            putchar(*ptr);
        }
    }
}

void lowerToUpper(char* ptr){
    for(;*ptr!='\0';ptr++){
        if(*ptr>='a' && *ptr<='z'){
            putchar(*ptr-32);
        }else{
            putchar(*ptr);
        }
    }
}

