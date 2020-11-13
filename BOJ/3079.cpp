#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int n, m;
ll arr[100005];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	ll st = 0, en = m * (*max_element(arr, arr + n));
	while (st + 1 < en) {
		ll mid = (st + en) / 2;

		ll cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cnt += (mid / arr[i]);
		}

		if (cnt >= m) en = mid;
		else st = mid;
	}
	printf("%lld", en);
}
