#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, k, id, m;
		scanf("%d%d%d%d", &n, &k, &id, &m);

		int submit[105] = { 0, };
		int score[105] = { 0, };
		int timee[105] = { 0, };
		int correct[105][105] = { 0, };

		for (int ti = 0; ti < m; ti++)
		{
			int i, j, s;
			scanf("%d%d%d", &i, &j, &s);
			submit[i]++;
			timee[i] = ti;
			if (correct[i][j] < s) {
				score[i] += s - correct[i][j];
				correct[i][j] = s;
			}
		}
			
		int ans = 1;
		for (int i = 1; i <= n; i++)
		{
			if (id == i) continue;
			if (score[id] < score[i]) ans++;
			else if (score[id] == score[i]) {
				if (submit[id] > submit[i]) ans++;
				else if (submit[id] == submit[i]) {
					if (timee[id] > timee[i]) ans++;
				}
			}
		}
		printf("%d\n", ans);
	}

}
