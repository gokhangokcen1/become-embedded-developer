#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printReverse(char*);

int main(){

    char message[100];
    puts("enter a sentence");
    fgets(message, sizeof(message), stdin);

    printReverse(message);


    return 0;
}

void printReverse(char* ptr){
    int i =0, length=0;
    length=strlen(ptr);
    for(i=length-1;i>=0;i--)
        putchar(*(ptr+i));
    printf("\n\n");
}
