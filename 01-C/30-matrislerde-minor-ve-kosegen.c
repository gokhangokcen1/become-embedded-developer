#include <stdio.h>
#include <stdlib.h>

void matrixPrint(int unit, int matrix[unit][unit]);
int main(){
    int unit, i, j;
    printf("kaca kac matris: ");
    scanf("%d", &unit);
    int matrix[unit][unit];

    for(i=0;i<unit;i++){
        for(j=0;j<unit;j++){
            matrix[i][j] = 0;
        }
    }

    for(i=0;i<unit;i++){
        matrix[i][i]=1;
        matrix[i][unit-1-i] = 1;
        }

    matrixPrint(unit, matrix);


    return 0;
}

void matrixPrint(int unit, int matrix[unit][unit]){

    for(int i=0; i<unit;i++){
        for(int j=0; j<unit; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
