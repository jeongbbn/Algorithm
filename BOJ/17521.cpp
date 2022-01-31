#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef unsigned long long ll;

int n, w;
ll arr[20], ans;

void f(int k, ll coin, ll money) {
	if (k == n) {
		ans = max(ans, money);
		return;
	}

	ll cnt = money / arr[k];
	//buy
	f(k + 1, coin + cnt, money - arr[k] * cnt);

	//sell
	f(k + 1, 0, money + arr[k] * coin);

	//continue
	f(k + 1, coin, money);
}

int main() {
	scanf("%d%d", &n, &w);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}
	ans = w;
	f(0, 0, w);
	printf("%lld", ans);
}
