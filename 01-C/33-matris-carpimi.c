#include <stdio.h>
#include "matrix.h"

int main() {
    int x[MAX_SIZE][MAX_SIZE], y[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int i, j, k, sum;
    int xrows, xcolumns, yrows, ycolumns;

    printf("x matrisinin satir ve sutununu gir: ");
    scanf("%d%d", &xrows, &xcolumns);
    readMatrix(xrows, xcolumns, x);

    printf("y matrisinin satir ve sutununu gir: ");
    scanf("%d%d", &yrows, &ycolumns);
    readMatrix(yrows, ycolumns, y);

    if (xcolumns != yrows) {
        printf("Carpma islemi yapilamaz: x'in sutun sayisi y'nin satir sayisina esit olmali.\n");
    } else {
        for (i = 0; i < xrows; i++) {
            for (j = 0; j < ycolumns; j++) {
                sum = 0;
                for (k = 0; k < xcolumns; k++) {
                    sum += x[i][k] * y[k][j];
                }
                result[i][j] = sum;
            }
        }

        printf("Sonuc matrisi:\n");
        printMatrix(xrows, ycolumns, result);
    }

    return 0;
}