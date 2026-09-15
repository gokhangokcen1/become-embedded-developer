#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE* fptr;
    char data[60];
    fptr = fopen("data/data.txt","w");
    if(fptr == NULL){
        printf("File Open Unsuccessful!\n");
    }else{
        printf("Enter a sentence:");
        fgets(data, sizeof(data), stdin);

        fprintf(fptr,"cumleniz:%s", data);

        printf("Data was written to File successfully!\n");
    }
    fclose(fptr);
    return 0;
}
