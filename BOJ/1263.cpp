#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

int n, s, t;
vector<pi>v;
bool flag;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> t >> s;
		v.push_back({ -s,  -t});
	}
	sort(v.begin(), v.end());

	int now = INF;
	for (int i = 0; i < v.size(); i++)
	{
		int t = -v[i].second;
		int s = -v[i].first;

		if (now > s) now = s;

		if (now - t < 0) {
			flag = 1; break;
		}
		now -= t;
	}
	if (now < 0 || flag) cout << -1;
	else cout << now;
}
