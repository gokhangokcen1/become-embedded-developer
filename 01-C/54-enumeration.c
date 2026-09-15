#include <stdio.h>
#include <stdlib.h>

enum Level{
    SMALL=1, //verdigin sayi ardışık olarak artar
    MEDIUM,
    LARGE,
    XLARGE
};

enum Correct{
    FALSE,
    TRUE
};

int main(){

    enum Level myConst;
    myConst=MEDIUM;
    switch(myConst){
        case 1: printf("small level\n");break;
        case 2: printf("medium level\n");break;
        case 3: printf("large level\n");break;
        case 4: printf("xlarge level\n");break;
    }

    enum Correct Corr;
    Corr=FALSE;

   if(Corr)
       printf("Islem basarili - %d\n", Corr);
   else
       printf("Islem basarisiz - %d\n", Corr);

    return 0;
}
