#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    printf("Nhap cap cua ma tran: ");
    scanf("%d", &n);

    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Nhap cac phan tu cua ma tran:\n");
    double sum = 0;
    for (int i = 0; i < n; i++) {
        long long max = 0;
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        sum += max;
    }

    printf("Tong cac phan tu lon nhat tren moi hang la: %lf\n", sum);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}