#include<iostream>
#include<string.h>
using namespace std;

const int MAX = 100;

int x[MAX];
int d1, h, n;

void solution() {
    for (int i = 1; i <= n; i++) cout << x[i];
    cout << endl;
}

void TRY(int k) {
    for (int i = 0; i <= 1; i++) {
        x[k] = i;
        if (i == 1) d1++;
        if (k == n) {
            if (d1 == h) solution();
        }
        else TRY(k + 1);
        if (i == 1) d1--;
    }
}

int main() {
    cout << "Ho Va Ten: DoanVietThang\n";
    cout << "MSSV: 20194165\n\n";
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> h;
        memset(x, 0, sizeof x);
        TRY(1);
    }
}