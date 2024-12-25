// Bai 36: N!!
#include <stdio.h>

void giaithua2(int A[], long n, long *m);

int main(){
    long n;
    int A[100000];
    long m_value = 0;
    long *m = &m_value;
    printf("Nhap n: ");
    scanf("%ld", &n);
    giaithua2(A, n, m);
    printf("Giai thua cua %ld la: ", n);
    for (int i = *m - 1; i >= 0; i--){
        printf("%d", A[i]);
    }
    return 0;
}

void giaithua2(int A[], long n, long *m){
    long i, j;
    *m = 1;
    A[0] = 1;
    unsigned long long int tich;
    for(i = 2 + (n % 2); i <= n; i += 2){
        unsigned long long int r = 0;
        for(j = 0; j < *m; j++){
            tich = A[j] * i + r;
            A[j] = tich % 10;
            r = tich / 10;
        }
        while(r > 0){
            A[*m] = r % 10;
            r /= 10;
            (*m)++;
        }
    }
}