#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n;
int arr[20];
int pluss, minuss, multi, divv;
int maxx = -INF;
int minn = INF;
int sum = 0;
void dfs(int k, int pl, int mi, int mu, int di) {
	if (k == n-1) {
		maxx = max(sum, maxx);
		minn = min(sum, minn);
		return;
	}

	if (pl < pluss) {
		int tmp = sum;
		sum = (sum + arr[k + 1]);
		dfs(k + 1, pl + 1, mi, mu, di);
		sum = tmp;
	}

	if (mi < minuss) {
		int tmp = sum;
		sum = (sum - arr[k + 1]);
		dfs(k + 1, pl, mi + 1, mu, di);
		sum = tmp;
	}

	if (mu < multi) {
		int tmp = sum;
		sum = (sum * arr[k + 1]);
		dfs(k + 1, pl, mi, mu + 1, di);
		sum = tmp;
	}

	if (di < divv) {
		int tmp = sum;
		sum = (sum / arr[k + 1]);
		dfs(k + 1, pl, mi, mu, di + 1);
		sum = tmp;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	scanf("%d%d%d%d", &pluss, &minuss, &multi, &divv);

	sum = arr[0];
	dfs(0, 0, 0, 0, 0);
	printf("%d\n%d", maxx, minn);
}
