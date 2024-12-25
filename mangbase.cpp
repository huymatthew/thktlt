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

int main(){
    int n;
    int A[100000];
    printf("Nhap n: ");
    scanf("%d", &n);

    return 0;
}