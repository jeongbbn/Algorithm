#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000000
typedef pair<int, string>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int s, t, minn = INF;
vector<string>ans;
queue<pi>q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int dist = q.front().second.length();
		string str = q.front().second;
		q.pop();

		if (dist > minn) continue;
		if (x == t && dist <= minn) {
			minn = dist;
			ans.push_back(str);
		}

		if (x != 1 && t / x >= x) {
			q.push({ x*x, str + "*" });
		}
		if (t >= x + x) {
			q.push({ x + x, str + "+" });
		}
	}
	if (ans.size() > 0) {
		sort(ans.begin(), ans.end());
		cout << ans[0];
		return;
	}
	printf("-1");
}

int main() {
	scanf("%d%d", &s, &t);

	q.push({ s ,""});
	q.push({ 1, "/"});
	if (s == t) { printf("0");	return 0; }
	if (t == 0) { printf("-"); return 0; }
	bfs();

}
