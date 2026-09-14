#include <stdio.h>
#include <stdlib.h>

int main(){
    char myLetters[5] = {'x','y','z','a', 'f'};
    int myNumbers[5] = {7,1,25,40,5};
    int i;

    printf("myLetters Array\n");
    printf("---------------\n");
    for(i=0;i<5;i++){
        printf("myLetter[%d] : %c\n", i, *(myLetters+i));
    }
    printf("myNumbers Array\n");
    printf("---------------\n");
    for(i=0;i<5;i++){
        printf("myNumber[%d] : %d\n", i, *(myNumbers+i));
                }

    printf("myLetters Array Addresses\n");
    printf("---------------\n");
    for(i=0;i<5;i++){
        printf("myLetter[%d] : %p\n", i, myLetters+i);
    }
    printf("myNumbers Array Addresses\n");
    printf("---------------\n");
    for(i=0;i<5;i++){
        printf("myNumber[%d] : %p\n", i, myNumbers+i);
                }





    return 0;
}
