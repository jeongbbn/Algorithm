#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, key[10];
bool visit[10];

void dfs(int k) {
	if (k == n) {
		for (int i = 0; i < k; i++)
			printf("%d ", key[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visit[i]) continue;
		visit[i] = 1;
		key[k] = i;
		dfs(k + 1);
		visit[i] = 0;
	}
}

int main() {
	scanf("%d", &n);
	dfs(0);
}
