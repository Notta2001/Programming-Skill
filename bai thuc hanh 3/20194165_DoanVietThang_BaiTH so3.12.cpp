#include<iostream>
#include<vector>
using namespace std;
#define Max 100005
typedef long long ll;
typedef vector<ll> vi;
vector<vi> node;
int n, k, m;
int cnt;
int sum;
bool kt[Max];
int kq[Max];
vi ket_qua;
void input()
{
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
}
void xuli(int x)
{
	kt[x] = true;
	for (int i = 0; i < node[x].size(); i++)
	{
		if (kt[node[x][i]]) continue;
		else
		{
			cnt++;
			if (cnt == k) sum++;
			else
			{
				kt[node[x][i]] = true;
				xuli(node[x][i]);
			}
		}
		kt[node[x][i]] = false;
		cnt--;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << "Ho Va Ten: DoanVietThang\n";
	cout << "MSSV: 20194165\n\n";
	cin >> n >> k;
	cin >> m;
	cnt = 0;
	sum = 0;
	for (int i = 1; i <= n; i++)
		kt[i] = false;
	node.resize(n + 1, vi(0));
	input();
	for (int i = 1; i <= n; i++)
	{
		xuli(i);
		kt[i] = false;
		cnt = 0;
	}
	cout << sum / 2;
	return 0;
}
