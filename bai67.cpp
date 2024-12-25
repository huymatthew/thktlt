// Quick sort
#include <stdio.h>
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void quicksort(int A[], int low, int high) {
    if (low < high) {
        int pivot = A[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (A[j] > pivot) {
                i++;
                swap(A[i], A[j]);
            }
        }
        swap(A[i + 1], A[high]);
        int pi = i + 1;
        quicksort(A, low, pi - 1);
        quicksort(A, pi + 1, high);
    }
}
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
    nhapmang(A, n);
    xuatmang(A, n);
    quicksort(A, 0, n - 1);
    xuatmang(A, n);
    return 0;
}