#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, m;
int ans[105][5];
vector<int>adj[105];
pi arr[155];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a < b) arr[i] = { a,b };
		else arr[i] = { b,a };
	}

	sort(arr, arr + m);
	for (int i = 0; i < m; i++)
	{
		int x = arr[i].first;
		int y = arr[i].second;

		for (int i = 1; i <= 4; i++)
			if (ans[x][i] == 0 || ans[x][i] == 2) {ans[x][i] = 2; break;}

		for (int i = 1; i <= 4; i++)
			if(ans[x][i] == 2) ans[y][i] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (ans[i][j] == 0 || ans[i][j] == 2) { ans[i][j] = 2; break; }
		}
	}



	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (ans[i][j] == 2) { printf("%d", j); break; }
		}
	}
}
