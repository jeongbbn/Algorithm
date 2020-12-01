#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int n, k, arr[1000005];

int main() {
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int st = 0, en = n + 1;
	bool flag = 0;
	while (st + 1 < en) {
		int mid = (st + en) / 2;

		int cnt = 0, maxx = 0;
		for (int i = 0; i < n; i++)
		{
			if (i >= mid && arr[i - mid] == 1) cnt--;
			if (arr[i] == 1) cnt++;

			maxx = max(cnt, maxx);
		}
		if (maxx >= k) en = mid;
		else st = mid;
	}

	if (en == n + 1) printf("-1");
	else printf("%d", en);
}
