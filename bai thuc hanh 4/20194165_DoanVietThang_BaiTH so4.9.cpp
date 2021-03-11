
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <numeric>
#include <chrono>
#include <random>
#include <functional>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <array>
#include <bitset>
#include <unordered_map>
using namespace std;

void solve() {

}

vector<int> dijkstra(const vector< vector< pair<int, int> > >& adj) {
    priority_queue<pair<int, int>>Q;
    vector<int> d(adj.size(), INT_MAX);
    d[0] = 0;
    Q.push({ 0,0 });
    while (!Q.empty()) {
        int u = Q.top().second;
        int du = -Q.top().first;
        Q.pop();
        //for(int i = 0; i < n; i++) cout << d[i] << " ";
        if (d[u] != du) continue;
        for (const auto& x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push({ -d[v], v });
            }
        }
    }
    return d;
}


int main() {
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj](int u, int v, int w) {
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (unsigned int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

}

