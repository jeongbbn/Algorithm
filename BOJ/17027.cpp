#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, ans;
pii arr[105];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		arr[i] = { {a,b},c };
	}

	for (int x = 1; x <= 3; x++)
	{
		int shell[4] = { 0, };
		shell[x] = 1;

		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			int bfr = arr[i].first.first;
			int nxt = arr[i].first.second;
			int g = arr[i].second;

			int tmp;
			tmp = shell[bfr];
			shell[bfr] = shell[nxt];
			shell[nxt] = tmp;

			if (shell[g] == 1) cnt++;
		}
		ans = max(ans, cnt);
	}
	printf("%d", ans);
}
