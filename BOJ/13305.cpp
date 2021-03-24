#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef unsigned long long ll;
typedef pair<ll, ll>pi;
typedef pair<int, pair<int, int>>pii;

pi arr[1000005];
int n;
ll ans, cost;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%lld", &arr[i].second);
	}
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1) continue;
		scanf("%lld", &arr[i].first);
	}

	cost = arr[0].first;
	ans = arr[0].second * cost;
	for (int i = 1; i < n - 1; i++)
	{
		cost = min(cost, arr[i].first);
		ans += cost * arr[i].second;
	}
	printf("%lld", ans);
}
