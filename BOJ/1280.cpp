#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef long long ll;
typedef pair<ll, int>pi;
typedef pair<int, pair<int, int>>pii;

int n;
ll arr[200005];
ll ans = 1;
int idx[200005];
pi sorted[200005];
vector<ll>tree, cnt;

void update(int i, ll diff) {
	while (i < tree.size()) {
		tree[i] = (tree[i] + diff);
		cnt[i] = (cnt[i] + 1);
		i += (i&-i);
	}
}

ll sum(int i) {
	ll tmp = 0;
	while (i > 0) {
		tmp += tree[i];
		i -= (i&-i);
	}
	return tmp;
}

ll count(int i) {
	ll tmp = 0;
	while (i > 0) {
		tmp = (tmp + cnt[i]);
		i -= (i&-i);
	}
	return tmp;
}

int main() {
	scanf("%d", &n);
	tree.resize(n + 1);
	cnt.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &arr[i]);
		sorted[i] = { arr[i],i };
	}

	sort(sorted + 1, sorted + n + 1);

	for (int i = 1; i <= n; i++)
		idx[sorted[i].second] = i;

	update(idx[1], arr[1]);
	for (int i = 2; i <= n; i++)
	{
		ll high = count(n) - count(idx[i]);
		ll low = count(idx[i] - 1);
		ll tmp1 = 0, tmp2 = 0;

		if (high > 0) {
			ll a = (sum(n) - sum(idx[i]));
			ll b = (high * arr[i]);
			tmp1 = (a - b) % mod;
		}

		if (low > 0) {
			ll c = (low * arr[i]);
			ll d = sum(idx[i] - 1);
			tmp2 = (c - d) % mod;
		}
		update(idx[i], arr[i]);
		ans = (ans * (tmp1 + tmp2)% mod) % mod;
	}
	printf("%lld", ans % mod);
}
