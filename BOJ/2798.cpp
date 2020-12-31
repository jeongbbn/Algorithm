#include <bits/stdc++.h>
using namespace std;

int n, m, arr[105], sum, ans = -1;
bool check[105];

void C(int k, int idx) {
	if (k == 3) {
		if (sum <= m) ans = max(ans, sum);
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (check[i]) continue;
		check[i] = 1;
		sum += arr[i];
		C(k + 1, i + 1);
		sum -= arr[i];
		check[i] = 0;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	C(0, 0);
	printf("%d", ans);
}
