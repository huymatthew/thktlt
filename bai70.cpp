#include <stdio.h>

void nhapmang(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
}

void xuatmang(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void chenPhanTu(int A[], int &n, int val) {
    int i = n - 1;
    while (i >= 0 && A[i] > val) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = val;
    n++;
}

void tronMang(int A[], int &nA, int B[], int nB) {
    for (int i = 0; i < nB; i++) {
        chenPhanTu(A, nA, B[i]);
    }
}

int main() {
    int nA, nB;
    int A[200000]; // Đảm bảo đủ lớn để chứa cả hai mảng
    int B[100000];

    printf("Nhap so phan tu cua mang A: ");
    scanf("%d", &nA);
    nhapmang(A, nA);

    printf("Nhap so phan tu cua mang B: ");
    scanf("%d", &nB);
    nhapmang(B, nB);
    xuatmang(A, nA);

    tronMang(A, nA, B, nB);
    xuatmang(A, nA);

    return 0;
}