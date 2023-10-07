#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void Zhjz(int n,int m) {
    if (n < m) printf("%d",n);
    else {
        Zhjz(n / m, m); printf("%d", n % m);
    }
}
int main() {
    int n, m;
    scanf("%d%d", & n, &m);
    Zhjz(n, m);
}
