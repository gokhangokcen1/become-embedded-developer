#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE* fptr;
    char data[100];
    fptr = fopen("data/data.txt","r");
    if(fptr == NULL){
        printf("File Open Unsuccessful!\n");
    }else{
        while(fgets(data,100,fptr)){
            printf("%s",data);
        }
    }
    fclose(fptr);
    return 0;
}
