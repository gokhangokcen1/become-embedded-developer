#include <stdio.h>
#include <stdlib.h>

int main(){

    int number;
    number = 7; //0111
    number &= 3; //0011
    // 0111 & 0011 = 0011 = 3
    printf("7 & 3 = %d\n", number);
    number &= 12; //1100
                  //0011 & 1100 = 0000 = 0
    printf("3 & 12 = %d\n", number);

    int number2;
    number2 = 7; 
    number2 |=3; // 0111 | 0011 = 0111 = 7
    printf("7 | 3 = %d\n", number2);
    
    int number3;
    number3 = 7; //her ikisi başarılı ya da başarısızsa 0 dön
    number3^=3; //0111 ^ 0011 = 0100 = 4
    printf("7 ^ 3 = %d\n", number3); 
    
    int number4;
    number4 = 7;
    number4 <<=2; //0000 0111 -> 0001 1100 = 28
    printf("7 << 2 = 28\n");


    int number5;
    number5 = 7;
    number5 >>=2; //0000 0111 -> 0000 0001 = 1
    printf("7 >> 2 = 1\n");

    return 0;
}
