// Kiem tra Fibonacci
#include <stdio.h>

void fibonacci(long long n){
    if (n == 1) printf("%lld la so Fibonacci\n", n);
    long long a = 0, b = 1, c;
    while (b <= n){
        c = a + b;
        a = b;
        b = c;
    }
    if (a == n || b == n) printf("%lld la so Fibonacci\n", n);
    else printf("%lld khong phai la so Fibonacci\n", n);
}
int main(){
    long long n;
    printf("Nhap n: ");
    scanf("%lld", &n);
    fibonacci(n);
    return 0;
}