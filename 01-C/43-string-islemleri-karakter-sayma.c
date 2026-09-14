#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findLength(char*);
int main(){

   char message[100];

   puts("enter a sentence:");
   fgets(message, sizeof(message), stdin);
   printf("length: %d\n", findLength(message));


    return 0;
}

int findLength(char* ptr){
    return strlen(ptr);
}
