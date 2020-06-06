#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> pii;

int n, k;
queue<pi>q;
int ans=INF;
vector<int>visit(100005, INF);
bool outrange(int a) {
	if (a < 0 || a>100000) return 1;
	return 0;
}
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == k) {
			ans = min(ans, cnt);
		}
		if (cnt > ans) continue;

		if (!outrange(x * 2) && visit[x * 2] > cnt) {
			q.push({ x * 2,cnt });
			visit[x * 2] = cnt;
		}

		if (!outrange(x + 1) && visit[x + 1] > cnt+1) {
			q.push({ x + 1,cnt + 1 });
			visit[x + 1] = cnt + 1;
		}

		if (!outrange(x - 1) && visit[x - 1] > cnt + 1) {
			q.push({ x - 1,cnt + 1 });
			visit[x - 1] = cnt + 1;
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);

	q.push({ n,0 });
	visit[n] = 0;
	bfs();
	printf("%d", ans);

}
