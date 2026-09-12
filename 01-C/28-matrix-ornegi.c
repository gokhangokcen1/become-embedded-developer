#include <stdio.h>
#include <stdlib.h>


void matrixPrint(int matrix[][4]);

int main(){

    int matrix[3][4];

    int i, j;

    for(i = 0; i<3; i++){
        for(j = 0; j<4; j++){
            matrix[i][j] = i+j;
        }
    }

    matrixPrint(matrix);


    return 0;
}


void matrixPrint(int matrix[][4]){

    for(int i=0; i<3;i++){
        for(int j=0; j<4; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
