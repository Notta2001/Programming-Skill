#include <iostream>
#include <map>
using namespace std;

void solve() {

}

template<class T>
map<T, double> fuzzy_set_union(const map<T, double>& a, const map<T, double>& b) {
    map<T, double> c = a;
    for (auto x : b) {
        auto p = c.find(x.first);
        if (p != c.end()) {
            double maxRes = max(x.second, (*p).second);
            (*p).second = ((*p).second != maxRes) ? maxRes : (*p).second;
            /*if((*p).second != maxRes) {
                (*p).second = maxRes;
            }*/
        }
        else c.insert({ x.first, x.second });
    }
    return c;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double>& a, const map<T, double>& b) {
    map<T, double> c;
    for (auto it : a) {
        for (auto i : b) {
            if (it.first == i.first) {
                double minRes = (it.second <= i.second) ? it.second : i.second;
                c.insert({ it.first,minRes });
            }
        }
    }
    return c;
}

template<class T>
void print_fuzzy_set(const map<T, double>& a) {
    cout << "{ ";
    for (const auto& x : a) {
        cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    cout << endl;
}

int main() {
    map<int, double> a = { {1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7} };
    map<int, double> b = { {1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1} };
    cout << "A = "; print_fuzzy_set(a);
    cout << "B = "; print_fuzzy_set(b);
    map<int, double> c = fuzzy_set_union(a, b);
    map<int, double> d = fuzzy_set_intersection(a, b);
    cout << "Union: "; print_fuzzy_set(c);
    cout << "Intersection: "; print_fuzzy_set(d);

}

