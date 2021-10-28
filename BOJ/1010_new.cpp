#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pi;

int n;
ll C[35][35];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= 30; i++)
	{
		C[i][0] = 1; C[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		cout << C[b][a] << "\n";
	}
}
