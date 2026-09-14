#include <stdio.h>
#include <stdlib.h>

int main(){
    char myLetters[7] = {'a','b','c','d','e','f','x'};

    printf("ilk elemanın adresi: %p\n", &myLetters[0]);
    printf("ilk elemanın adresi: %p\n", myLetters);
    printf("ikinci elemanın adres: %p\n", &myLetters[1]);
    printf("ikinci elemanın adres: %p\n", myLetters + 1);
    printf("ucuncu elemanın adres: %p\n", &myLetters[2]);
    printf("ucuncu elemanın adres: %p\n", myLetters + 2);

    printf("ilk elemanın degeri: %c\n", myLetters[0]);
    printf("ilk elemanın degeri: %c\n", *myLetters);

    printf("ikinci elemanın degeri: %c\n", myLetters[1]);
    printf("ikinci elemanın degeri: %c\n", *(myLetters + 1));

    return 0;
}
