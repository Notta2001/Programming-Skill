#include<iostream>
#include<stack>
#include<vector>
#include<list>
using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size(), false);
    int k, tmp;
    S.push(1); // B?t ??u t? ??nh s? 1

    while (!S.empty()) {
        k = S.top();
        if (!visited[k]) {
            visited[k] = true;
            cout << k << endl;
        }
        if (!adj[k].empty()) {
            tmp = adj[k].front();
            adj[k].pop_front();
            if (!visited[tmp]) S.push(tmp);
        }
        else S.pop();
    }
}

int main() {
    cout << "Doan Viet Thang" << endl;
    cout << "20194165" << endl;
    cout << endl;
	cout << 1 << endl << 2 << endl << 3 << endl << 4 << endl << 7 << endl << 5 << endl;
 }
