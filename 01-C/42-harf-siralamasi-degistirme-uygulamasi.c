#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void characterScroll(char*, int);

int main() {
    char characters[7] = {'Y', 'a', 'z', 'i', 'l', 'i', 'm'};
    int size = sizeof(characters) / sizeof(characters[0]);
    characterScroll(characters, size);
    return 0;
}

void characterScroll(char* characters, int size) {
    int i = 0, j = 0;
    for (i = 0; i < size + 1; i++) {
        for (j = i; j < size; j++) {
            printf("%c", *(characters + j));
        }
        for (j = 0; j < i; j++) {
            printf("%c", *(characters + j));
        }
        printf("\n");
    }
}
