#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define ll long long
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
    printf("\n");
}

void sangEratosthenes(bool isPrime[], ll maxVal) {
    for (int i = 2; i <= maxVal; i++) {
        isPrime[i] = true;
    }
    for (int p = 2; p * p <= maxVal; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= maxVal; i += p) {
                isPrime[i] = false;
            }
        }
    }
}
void giatrilonnhat(int A[], bool isPrime[], int n){
    int max = -1;
    for (int i = 0; i < n; i++){
        if (A[i] > max && isPrime[A[i]]){
            max = A[i];
        }
    }
    if (max == -1) printf("Khong co so nguyen to trong mang\n");
    else printf("Gia tri nguyen to lon nhat la: %d\n", max);
}
void kiemtraNguyenTo(int A[], int n) {
    int maxVal = 1000000;
    bool isPrime[maxVal + 1];
    sangEratosthenes(isPrime, maxVal);
    giatrilonnhat(A, isPrime, n);
}

int main(){
    int n;
    int A[100000];
    printf("Nhap n: ");
    scanf("%d", &n);
    nhapmang(A, n);
    xuatmang(A, n);
    kiemtraNguyenTo(A, n);
    return 0;
}