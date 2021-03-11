
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {

}

void print_vector(const vector<int>& a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int>& a) {
    int k = a.size();
    for (int i = 0; i < k; i++) {
        if (abs(a[i]) % 2 == 0) {
            a.erase(a.begin() + i);
            i--;
            k--;
            a.resize(k);
        }
    }

}

void sort_decrease(vector<int>& a) {
    sort(a.begin(), a.end(), greater<int>());
}

vector<int> merge_vectors(const vector<int>& a, const vector<int>& b) {
    vector<int> v(a.size() + b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), v.begin(), greater<int>());
    return v;
}



int main() {
    cout << "Doan Viet Thang" << endl;
    cout << "20194165" << endl;
    cout << endl;
    int m, n, u;
    std::vector<int> a, b;

    std::cin >> m >> n;
    for (int i = 0; i < m; i++) {
        std::cin >> u;
        a.push_back(u);
    }
    for (int i = 0; i < n; i++) {
        std::cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;

}
