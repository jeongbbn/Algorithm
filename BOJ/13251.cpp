#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int m, k, N;
double C[2505][2505];
vector<int>arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		N += a;
		arr.push_back(a);
	}
	cin >> k;

	C[0][0] = 1;
	for (int i = 1; i <= 2500; i++)
	{
		C[i][0] = 1; C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}

	double sum = 0;
	for (int i = 0; i < m; i++) {
		sum += C[arr[i]][k];
	}

	cout << fixed;
	cout.precision(18);
	cout << sum / C[N][k];
}
