#include <stdio.h>
#include <stdlib.h>

void matrixPrint(int matrix[][3]);
int main(){

    int matrix[2][3] = {
        {2,7,19},
        {3,8,12}
    };

    matrixPrint(matrix);

    matrix[1][2] = 44;

    matrixPrint(matrix);
    return 0;
}

void matrixPrint(int matrix[][3]){

    for(int i=0; i<2;i++){
        for(int j=0; j<3; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
