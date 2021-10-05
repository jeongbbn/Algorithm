#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define INF 1e9;
typedef long long ll;

int t;
ll n, m;
ll circle, tmp, full;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &n, &m);
		
		circle = 1;
		tmp = (m % 10);
		full = tmp;
		while (1) {
			tmp += m;
			tmp %= 10;
			if (tmp == (m % 10)) break;
			circle++;
			full += tmp;
		}
		ll ans = ((n / m) / circle) * full;
		ll size = ((n / m) % circle);

		tmp = 0;
		for (int i = 0; i < size; i++)
		{
			tmp += m;
			tmp %= 10;
			ans += tmp;
		}
		printf("%lld\n", ans);
	}
}
