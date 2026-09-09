#include <stdio.h>
#include <stdlib.h>

int main(){

    char myCharacter;

    printf("Enter a character:");
    scanf("%c", &myCharacter);

    if((myCharacter>='A') && (myCharacter <='Z')){
        printf("%c is an uppercase letter\n", myCharacter);
    }else if((myCharacter>='a') && (myCharacter<='z')){
        printf("%c is a lowercase letter\n", myCharacter);
    }else{
        printf("its not a char\n");
    }





    return 0;
}
