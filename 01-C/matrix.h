#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>

#define MAX_SIZE 50

static void readMatrix(int rows, int cols, int arr[][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

static void printMatrix(int rows, int cols, int arr[][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

#endif