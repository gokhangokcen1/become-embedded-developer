#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, j, row, a=0;
    char myLetter;

    printf("enter a letter");
    scanf("%c", &myLetter);
    printf("row number (odd number): ");
    scanf("%d", &row);
    for(i=0;i<row;i++){
        if(i<=row/2)
            a++;
        else
            a--;
        for(j=1;j<a;j++)
            printf(" ");

        printf("%c\n",myLetter);
    }


    return 0;
}
