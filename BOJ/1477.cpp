#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1'000'000'003
typedef unsigned long long ll;
typedef pair<ll, ll>pi;
typedef pair<int, pair<int, int>>pii;

int n, m, l;
vector<int>v;

int main() {
	cin >> n >> m >> l;
	v.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	v.push_back(l);
	sort(v.begin(), v.end());

	int len = 0;
	for (int i = 1; i < v.size(); i++)
	{
		len = max(len, v[i] - v[i - 1]);
	}

	int st = 0, en = len;
	while (st + 1 < en) {
		int mid = (st + en) / 2;

		int cnt = 0;
		for (int i = 1; i < v.size(); i++)
		{
			int dist = v[i] - v[i - 1] - 1;
			cnt += dist / mid;
		}

		if (cnt > m) st = mid;
		else en = mid;
	}
	printf("%d", en);
}
