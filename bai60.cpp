#include <stdio.h>

void nhapmang(int A[], int n){
    for (int i = 0; i < n; i++){
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
}

void xuatmang(int A[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
}
void xoaphantu(int A[], int &n, int k){
    for (int i = k; i < n - 1; i++){
        A[i] = A[i + 1];
    }
    n--;
}
int main(){
    int n;
    int A[100000];
    printf("Nhap n: ");
    scanf("%d", &n);
    nhapmang(A, n);
    xuatmang(A, n);
    xoaphantu(A, n, 0);
    xuatmang(A, n);
    return 0;
}