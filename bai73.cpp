#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-9

void doihang(double **matrix, int row1, int row2, int cols) {
    for (int i = 0; i < cols; i++) {
        double temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

void phepbiendoisocap(double **matrix, int rows, int cols) {
    int lead = 0;
    for (int r = 0; r < rows; r++) {
        if (lead >= cols) {
            return;
        }
        int i = r;
        while (fabs(matrix[i][lead]) < EPS) {
            i++;
            if (i == rows) {
                i = r;
                lead++;
                if (lead == cols) {
                    return;
                }
            }
        }
        doihang(matrix, i, r, cols);
        double lv = matrix[r][lead];
        for (int j = 0; j < cols; j++) {
            matrix[r][j] /= lv;
        }
        for (int i = 0; i < rows; i++) {
            if (i != r) {
                lv = matrix[i][lead];
                for (int j = 0; j < cols; j++) {
                    matrix[i][j] -= lv * matrix[r][j];
                }
            }
        }
        lead++;
    }
}

int main() {
    int n;
    printf("Nhap cap cua ma tran: ");
    scanf("%d", &n);

    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(n * 2 * sizeof(double));
    }

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
        for (int j = n; j < n * 2; j++) {
            matrix[i][j] = (i == j - n) ? 1 : 0;
        }
    }
    
    phepbiendoisocap(matrix, n, n * 2);

    printf("Ma tran nghich dao:\n");
    for (int i = 0; i < n; i++) {
        for (int j = n; j < n * 2; j++) {
            printf("%.3lf ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}