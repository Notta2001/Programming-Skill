
#include<stdio.h>
#include <iostream>
using namespace std;

int n;
int X[100], Y[100]; //# Lưu tọa độ các bước di chuyển của quân mã
int mark[100][100] = { 0 }; //# Đánh dấu vị trí các ô mà quân mã đã di chuyển qua

//# Mảng hx, hy mô tả 8 vị trí quân mã có thể di chuyển kể từ vị trí hiện tại
const int hx[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
const int hy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

//# In ra dãy các di chuyển tìm được
void print_sol() {
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}


int check(int x, int y) {
    if (x > 0 && x <= n && y > 0 && y <= n) return 1;
    return 0;
}
//# Thuật toán quay lui
void TRY(int k) {
    if (k > n * n) {
        print_sol();
        return;
    }
    for (int i = 0; i < 8; i++) {
        int xx = X[k - 1] + hx[i];
        int yy = Y[k - 1] + hy[i];
        if (mark[xx][yy] == 0 && check(xx, yy)) {
            X[k] = xx;
            Y[k] = yy;
            mark[xx][yy] = 1;
            TRY(k + 1);
            mark[xx][yy] = 0;
        }
    }
}

int main() {
    cout << "Ho Va Ten: DoanVietThang\n";
    cout << "MSSV: 20194165\n\n";
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    print_sol();
    return 0;
}

