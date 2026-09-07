#include <stdio.h>
#include <stdlib.h>

int main(){

    char myCity[16];
    printf("Enter a city:");
    scanf("%15s", myCity);
    //scanf yalnızca tek kelime alıyor, boşluktan sonrasını almıyor
    printf("Your city is %s", myCity);
    printf("\n\n");
    return 0;
}
