#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *fptr,*fptrcopy;
    fptr=fopen("data/data.txt","r");
    fptrcopy=fopen("data/datacopy.txt","w");
    if(fptr == NULL){
        printf("data.txt open unsuccessful!\n");
    }else{
        if(fptrcopy == NULL){
            printf("datacopy.txt open unsuccessful!\n");
        }else{
            while(!feof(fptr)){
                putc(getc(fptr),fptrcopy);
            }
            printf("The file has been copied\n");
        }
    }
    fclose(fptr);
    fclose(fptrcopy);
    return 0;
}
