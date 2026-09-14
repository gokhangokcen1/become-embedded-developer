#include <stdio.h>
#include <stdlib.h>
void myArray(int* numbers);

int main(){
    int numbers[6] = {1, 15, 6, 25, 8, 4};
    int i;
    printf("Onceki degerler\n");
    printf("---------------\n");
    for(i=0;i<6;i++){
        printf("numbers[%d] : %d\n", i, numbers[i]);
    }

    myArray(numbers);
    printf("sonraki degerler\n");
    printf("---------------\n");
    for(i=0;i<6;i++){
        printf("numbers[%d] : %d\n", i, numbers[i]);
    }

    return 0;
}

void myArray(int* numbers){
    int j;
    for(j=0;j<6;j++){
        *(numbers+j) *= 3;
    }
}
