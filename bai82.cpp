#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int drawMatrix(double **matrix, int rows, int cols , int offset, int from_value) {
    for (int i = offset; i < cols; i++) {
        matrix[offset][i] = from_value++;
    }
    for (int i = offset + 1; i < rows; i++) {
        matrix[i][cols - 1] = from_value++;
    }
    for (int i = cols - 2; i >= offset; i--) {
        matrix[rows - 1][i] = from_value++;
    }
    for (int i = rows - 2; i > offset; i--) {
        matrix[i][offset] = from_value++;
    }

    return from_value;
}
int main() {
    int rows, cols;
    printf("Nhap so hang va so cot cua ma tran: \n");
    scanf("%d%d", &rows, &cols);

    double **matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(cols * sizeof(double));
    }
    int from_value = 1;
    int offset = 0;
    int temp_rows = rows;
    int temp_cols = cols;
    while (offset < rows / 2 && offset < cols / 2) {
        from_value = drawMatrix(matrix, temp_rows, temp_cols, offset, from_value);
        temp_rows -= 1;
        temp_cols -= 1;
        offset++;
    }
    printf("Ma tran sau khi nhap la: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%0.0lf\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}