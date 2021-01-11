#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1'000'000'003
typedef unsigned long long ll;
typedef pair<ll, ll>pi;
typedef pair<int, pair<int, int>>pii;

ll n, arr[500005];

ll divide(ll st, ll en) {
	if (st + 1 == en) return arr[st] * arr[en];
	if (st == en) return 0;
	ll mid = (st + en) / 2;

	ll l = 0, r = 0;
	for (int i = st; i <= mid; i++) l += arr[i];
	for (int i = mid + 1; i <= en; i++) r += arr[i];
	ll sum = l * r;

	return sum + divide(st, mid) + divide(mid + 1, en);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	printf("%lld", divide(0, n - 1));
}	
