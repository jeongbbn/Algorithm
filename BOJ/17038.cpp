#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, m;
z
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		char d;
		int a, b, c = 0;
		scanf(" %c%d%d", &d, &a, &b);
		if (d == 'D') c = 1; 
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
		unionn(a, b);
	}

	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = find(i);
		if (chk[x]) continue;
		sum++;
		chk[x] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		coloring(i);
		if (impossible) break;
	}

	if (impossible) printf("0");
	else {
		printf("1");
		for (int i = 0; i < sum; i++)
		{
			printf("0");
		}
	}
}
