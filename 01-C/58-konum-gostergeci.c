#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE* fptr;
    char data[100];
    fptr = fopen("data/data.txt","r");
    if(fptr == NULL){
        printf("File open unsuccessful!\n");
    }else{
        printf("Konum gostergeci yeri:%ld\n",ftell(fptr));
        fseek(fptr,50,SEEK_SET);
        printf("Konum gostergeci yeri:%ld\n",ftell(fptr));
        fgets(data,100,fptr);
        printf("%s\n",data);
        printf("Konum gostergeci yeri:%ld\n",ftell(fptr));
        rewind(fptr);
        printf("Konum gostergeci yeri:%ld\n",ftell(fptr));
        fgets(data,100,fptr);
        printf("%s\n",data);
    }
    fclose(fptr);
    return 0;
}
