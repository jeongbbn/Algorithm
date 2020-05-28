#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int arr[25][25];
int n;
int minn = INF;
int key[15];
bool visit[25];



void dfs(int idx, int k) {
	if (k == n / 2) {

		int antikey[15], t = 0;
		for (int i = 0; i < n; i++)
		{
			if (visit[i]) continue;
			antikey[t++] = i;
		}

		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				sum1 += arr[key[i]][key[j]];
				sum2 += arr[antikey[i]][antikey[j]];
			}
		}

		int ans = abs(sum1 - sum2);
		minn = min(ans, minn);
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (visit[i]) continue;
		visit[i] = 1;
		key[k] = i;
		dfs(i, k + 1);
		visit[i] = 0;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	dfs(0, 0);
	printf("%d", minn);


}
