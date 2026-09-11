#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(){
    double myValue, myArray[10];
    int choice, index;

    do{
        printf("------------------------------\n");
        printf("make a choice -1 to exit\n");
        printf("\t1. write to array\n");
        printf("\t2. read to array\n");
        scanf("%d", &choice);
        if(choice == -1) break;
        if(choice != 1 && choice != 2){
            printf("kanki bu ne\n");
            continue;
        }
        printf("enter array index:");
        scanf("%d", &index);
        if(index<=0 || index > 9){
            printf("index should be in the 0-9\n");
            continue;
        }
        switch(choice){
            case 1: printf("enter the value: ");
                    scanf("%lf", &myValue);
                    myArray[index]=myValue;
                    printf("The write operation is successful\n");
                    break;
            case 2: printf("myArray[%d]:%.2f\n\n", index, myArray[index]);
                    break;
        }

        }while(choice != -1);

        return 0;
    }
