#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

ll a, b, c, d, sum, dsum;

int main() {
	cin >> a >> b >> c >> d;
	sum = a * d + b * c;
	dsum = b * d;

	vector<ll>v;
	for (int i = 1; i * i <= dsum; i++)
	{
		if (dsum % i != 0) continue;
		v.push_back(i);
		if (i != dsum / i) v.push_back(dsum / i);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		if (sum % v[i] == 0) {
			printf("%lld %lld", sum / v[i], dsum / v[i]);
			return 0;
		}
	}
	printf("%lld %lld", sum, dsum);
}
