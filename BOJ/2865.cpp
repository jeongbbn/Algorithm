#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<double, int>pi;
typedef pair<double, pair<int, int>>pii;
typedef long long ll;

int n, m, k;
double ans;
vector<pi>v;
bool chk[105];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		for (int i = 0; i < n; i++)
		{
			int a; double b;
			scanf("%d %lf", &a, &b);
			v.push_back({ b,a});
		}
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int p = v[i].second;
		double score = v[i].first;

		if (!chk[p]) {
			chk[p] = 1;
			ans += score;
			cnt++;
		}
		if (cnt == k) break;
	}
	printf("%.1lf", ans);
}
