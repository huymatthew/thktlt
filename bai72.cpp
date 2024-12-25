#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-9

void doicot(double **matrix, int row1, int row2, int cols) {
    for (int i = 0; i < cols; i++) {
        double temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}
int timHang(double **matrix, int rows, int cols) {
    int rank = cols;
    for (int row = 0; row < rank; row++) {
        if (fabs(matrix[row][row]) > EPS) {
            for (int col = 0; col < rows; col++) {
                if (col != row) {
                    double mult = matrix[col][row] / matrix[row][row];
                    for (int i = 0; i < rank; i++) {
                        matrix[col][i] -= mult * matrix[row][i];
                    }
                }
            }
        } else {
            int reduce = 1;
            for (int i = row + 1; i < rows; i++) {
                if (fabs(matrix[i][row]) > EPS) {
                    doicot(matrix, row, i, cols);
                    reduce = 0;
                    break;
                }
            }
            if (reduce) {
                rank--;
                for (int i = 0; i < rows; i++) {
                    matrix[i][row] = matrix[i][rank];
                }
            }
            row--;
        }
    }
    return rank;
}

int main() {
    int n;
    printf("Nhap cap cua ma tran: ");
    scanf("%d", &n);

    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    int rank = timHang(matrix, n, n);
    printf("Hang cua ma tran la: %d\n", rank);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}