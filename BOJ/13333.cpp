#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, arr[1005], cnt[10005];
bool chk[10005];
int main() {
	scanf("%d", &n);
	fill(cnt, cnt + 10004, -1);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		cnt[arr[i]]++;
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		int k = arr[i];

		if (chk[k]) continue;

		int x = n - i;
		int y = i + 1;
		if(cnt[k] > 0) y += cnt[k];
		chk[k] = 1;
		if (x >= k && y <= n - k) {
			printf("%d", k);
			return 0;
		}
	}
}
