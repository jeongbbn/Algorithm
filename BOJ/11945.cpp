#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

int n, m, arr[15][15];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = m-1; j >= 0; j--)
			scanf("%1d", &arr[i][j]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr[i][j];
		cout << "\n";
	}
}
