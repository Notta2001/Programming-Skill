
#include <iostream>
#include <set>
using namespace std;

void solve() {

}

template<class T>
set<T> set_union(const set<T>& a, const set<T>& b) {
    set<T> c = a;
    for (const T& x : b) c.insert(x);
    return c;
}

template<class T>
set<T> set_intersection(const set<T>& a, const set<T>& b) {
    set<T> c;
    for (const T& x : a) {
        if (b.find(x) != b.end()) c.insert(x);
    }
    return c;
}

template<class T>
void print_set(const set<T>& a) {
    for (const T& x : a) {
        cout << x << ' ';
    }
    cout << endl;
}

int main() {
    set<int> a = { 1, 2, 3, 5, 7 };
    set<int> b = { 2, 4, 5, 6, 9 };
    set<int> c = set_union(a, b);
    set<int> d = set_intersection(a, b);

    cout << "Union: "; print_set(c);
    cout << "Intersection: "; print_set(d);

    return 0;

}

