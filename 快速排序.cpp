#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Algorithm>
#include<time.h>
using namespace std;
int a[100];

void qsort(int l, int r) {
    if (l >= r)return;
    int i = l, j = r, k = a[(l+r)/2];
    while (i <= j) {
        while (i <= j && a[j] > k)j--;
        while (i <=j && a[i] < k)i++;
        if (i > j)break;
        swap(a[i++], a[j--]);
    }
    qsort(l, j); qsort(i, r);
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
    srand(time(0));
    qsort(1, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}
