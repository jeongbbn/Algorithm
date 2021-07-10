#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, arr[10], key[10], maxx;
bool visit[10];

void dfs(int k) {
	if (k == n) {
		int sum = 0;
		for (int i = 0; i < n-1; i++)
			sum += abs(key[i] - key[i + 1]);

		maxx = max(sum, maxx);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visit[i]) continue;
		visit[i] = 1;
		key[k] = arr[i];
		dfs(k + 1);
		visit[i] = 0;
	}
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	dfs(0);
	printf("%d", maxx);
}
