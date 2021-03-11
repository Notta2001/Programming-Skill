#include<iostream>
using namespace std;

long long n, k1, k2, res = 0;
int x[200];

void print()
{
	for (int i = 0; i < n; ++i)
	{
		cout << x[i];
	}
	cout << endl;
}

void TRY(int k) 
{
	for (int i = k1; i <= k2; ++i) 
	{	
		for (int j = 0; j < i; j++)
		{	
			x[k + j] = 1;
		}
		k += i;
		if (k == n || k == (n - 1)) {
			print();
			res++;
		}
		else if (k + k1 <= n) TRY(k + 1);
		k -= i;
		for (int j = k; j < n; ++j) {
			x[j] = 0;
		}

	}
}

int main() {
	cout << "Ho Va Ten: DoanVietThang\n";
	cout << "MSSV: 20194165\n\n";
	cin >> n >> k1 >> k2;
	TRY(1);
	memset(x, 0, sizeof x);
	TRY(0);
}