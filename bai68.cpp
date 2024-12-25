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
void tongnguyento(int A[], bool isPrime[], int n){
    long long sum = 0;
    for (int i = 0; i < n; i++){
        if (isPrime[A[i]]){
            sum += A[i];
        }
    }
    printf("Tong cac so nguyen to trong mang la: %lld\n", sum);
}
void kiemtraNguyenTo(int A[], int n) {
    int maxVal = 1000000;
    bool isPrime[maxVal + 1];
    sangEratosthenes(isPrime, maxVal);
    tongnguyento(A, isPrime, n);
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