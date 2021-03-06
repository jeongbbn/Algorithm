#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, string>pi;
typedef pair<int, pair<int, int>>pii;
int t, n;

string bfs() {
	bool visit[20005][101] = { 0, };
	queue<pi>q;
	q.push({ n,"" });

	while (!q.empty()) {
		int bfr = q.front().first;
		int len = q.front().second.length();
		string str = q.front().second;
		q.pop();

		if (len > 100) continue;
		if (bfr == 0 && len ) {
			string tmp;
			for (int i = len - 1; i >= 0; i--)
			{
				tmp += str[i];
			}
			return tmp;
		}

		visit[bfr][len] = 1;

		for (int i = 0; i < 10; i++)
		{
			int x = bfr + (n*i);
			if (x % 10 == 1 || x % 10 == 0) {
				if (visit[x / 10][len + 1]) continue;
				visit[x / 10][len + 1] = 1;
				q.push({ x / 10, str + to_string(x % 10)});
			}
		}
	}
	return "BRAK";
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		string ans = bfs();
		cout << ans << "\n";
	}
}
