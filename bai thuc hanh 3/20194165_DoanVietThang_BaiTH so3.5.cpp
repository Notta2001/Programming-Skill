
#include<stdio.h>
#include <iostream>
using namespace std;

int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n - 1, k) + binom(n - 1, k - 1);
}

int c[1000][1000]; //c[duoi][tren]

int binom2(int n, int k) {
    /*for (int i = 0; i <= n; ++i) {
        c[i][0] = 1;
        c[i][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {                          
        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j)
        printf("%d ", c[i][j]);
        printf("\n");
    }*/
    int res = 1;
    int x = min(k, n - k);
    for (int i = 1; i <= x; i++) {
        res = res * n / i;
        n--;
    }
    return res;
}

int main() {
    cout << "Ho Va Ten: DoanVietThang\n";
    cout << "MSSV: 20194165\n\n";
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n) {
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= m; ++n) {
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}

