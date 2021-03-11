#include<iostream>
using namespace std;

struct Point {
    int first;
    int second;
};

double area(Point a, Point b, Point c) {

    double x1 = c.first - a.first;
    double y1 = c.second - a.second;
    double x2 = b.first - a.first;
    double y2 = b.second - a.second;
    return abs(x1 * y2 - x2 * y1) / 2;

}

int main() {
    cout << "Doan Viet Thang" << endl;
    cout << "20194165" << endl;
    cout << endl;
    Point a, b, c;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
    cout << area(a, b, c);
}
