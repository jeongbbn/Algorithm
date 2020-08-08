#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, string>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

ll n, cnt, tmp;
bool visit[1000005];
vector<ll>v;
bool sett[1000005];
map<ll, bool>m;

void C(int t, int cnt, ll sum, int maxx) {
	if (cnt == maxx) {
		tmp += (n / sum);
		return;
	}
	for (int i = t; i < v.size(); i++)
	{
		if (visit[i]) continue;
		visit[i] = 1;
		C(i, cnt + 1, sum * v[i], maxx);
		visit[i] = 0;
	}
}

int main() {
	scanf("%lld", &n);

	//소인수를 구함
	ll tempp = n;
	for (ll i = 2; i * i <= tempp; i++)
	{
		if (tempp == 1) break;
		while (tempp % i == 0) {
			if (!sett[i]) {
				v.push_back(i);
				sett[i] = 1;
			}
			tempp /= i;
		}
	}
	if (tempp != 1) v.push_back(tempp);

	for (int i = 1; i <= v.size(); i++)
	{
		tmp = 0;
		C(0, 0, 1, i);
		if (i % 2 == 1) cnt += tmp;
		else cnt -= tmp;
	}

	printf("%lld", n - cnt);
}
