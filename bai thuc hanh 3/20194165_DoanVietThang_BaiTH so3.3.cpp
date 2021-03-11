	#include<iostream>
	using namespace std;

	int n;
	int x[100], a[100][100], mark[100];
	int curr, best = INT_MAX;
	int cmin = INT_MAX;

	bool check(int k, int v)
	{
		if (!mark[v]) return true;
		return false;
	}

	void Try(int k) // thu buoc k
	{
		for (int v = 1; v <= n; v++) {// n la so truong hop o k
			if (check(k, v))
			{
				x[k] = v;
				curr += a[x[k - 1]][v];
				mark[v] = 1;
				if (k == n)
				{
					if ((curr + a[x[k]][1]) < best) best = curr + a[x[k]][1];
				}
				else if(curr+cmin*(n-k+1)<best) Try(k + 1);
				mark[v] = 0;
				curr -= a[x[k - 1]][v];
			}
		}
	}

	int main() {
		cout << "Ho Va Ten: DoanVietThang\n";
		cout << "MSSV: 20194165\n\n";
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> a[i][j];
				if (i != j && a[i][j] < cmin) cmin = a[i][j];
				// cmin = (i==j) ? cmin : min(cmin,a[i][j]);
			}
		}
		mark[1] = 1;
		x[1] = 1;
		Try(2);
		cout << best << endl;
	}


	//DONE
