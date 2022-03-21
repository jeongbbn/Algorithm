#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, cnt, ans;
int d = INF;
pi arr[1000005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		arr[i] = { a,b };
		if (b == 0) cnt++;
	}

	if (cnt == 0) {
		printf("1");
		return 0;
	}
	else if (cnt == n) {
		printf("0");
		return 0;
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		int x = arr[i].first;
		int y = arr[i].second;

		if (y == 0) {
			if (i != 0 && arr[i - 1].second == 1)
				d = min(d, x - arr[i - 1].first);

			if (i != n - 1 && arr[i + 1].second == 1)
				d = min(d, arr[i + 1].first - x);
		}
	}

	d--;
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		int x = arr[i].first;
		int y = arr[i].second;

		if (flag != 0) {
			if (flag + d < arr[i].first) ans++;
		}
		if (y == 1) flag = arr[i].first;
		else flag = 0;
	}
	if (flag != 0) ans++;
	printf("%d", ans);
}
