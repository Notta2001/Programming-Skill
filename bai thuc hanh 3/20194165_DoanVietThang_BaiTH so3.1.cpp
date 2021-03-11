#include<iostream>
using namespace std;

int lucas(int n) {
	if (n == 0) return 2;
	else if (n == 1)return 1;
	else {
		return lucas(n - 1) + lucas(n - 2);
	}
}

int main() {
	cout << "Ho Va Ten: DoanVietThang\n";
	cout << "MSSV: 20194165\n\n";
	cout << lucas(5); 
}