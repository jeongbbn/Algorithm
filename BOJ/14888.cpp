#include <bits/stdc++.h>
using namespace std;
#define INF 2e9

int n, arr[15], m[4], sum;
int maxx = -INF, minn = INF;
void P(int k, int idx, int sum) {
	if (k == n - 1) {
		maxx = max(sum, maxx);
		minn = min(sum, minn);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int temp;
		if (m[i] == 0) continue;
		m[i]--;
		if (i == 0)
			P(k + 1, idx + 1, sum + arr[idx]);

		else if (i == 1)
			P(k + 1, idx + 1, sum - arr[idx]);

		else if (i == 2)
			P(k + 1, idx + 1, sum * arr[idx]);

		else if (i == 3)
			P(k + 1, idx + 1, sum / arr[idx]);

		m[i]++;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < 4; i++)
		scanf("%d", &m[i]);

	P(0, 1, arr[0]);

	printf("%d\n%d", maxx, minn);
}
