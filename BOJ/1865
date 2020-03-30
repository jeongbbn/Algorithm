#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;

/*
	1. 두 정점 사이에 간선이 여러개여도 상관이 없는 이유
		=> 어차피 거리가 가장 짧은 간선으로 갱신된다

	2. 시작점이 어디든 상관없음
		=>for(j 1~n) 정점탐색할 때, 알아서 휩쓸어줌
		단, 시작점의 mindist는 0이어야함

	3. 독립 컴포넌트의 존재 유무
		=> 이 문제는 단순하게 음수사이클 유무를 구하는거라
			INF인지 확인을 안해서 값이 엉망이 된다하더라도,
			갱신이 되는지안되는지만 보면 되기 때문에 상관없다.
*/

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {

		vector<pi>adj[505];
		int n, m, w;
		scanf("%d%d%d", &n, &m, &w);
		for (int i = 0; i < m; i++)
		{
			int s, e, t;
			scanf("%d%d%d", &s, &e, &t);
			adj[s].push_back({ e,t }); //양방향
			adj[e].push_back({ s,t });
		}
		for (int i = 0; i < w; i++)
		{
			int s, e, t;
			scanf("%d%d%d", &s, &e, &t);
			adj[s].push_back({ e,-t });
		}

		int mindist[505];
		fill(mindist + 1, mindist + 1 + n, INF);
		mindist[1] = 0;  //2

		bool flag = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int total = mindist[j];
				for (int k = 0; k < adj[j].size(); k++)
				{
					int nxt = adj[j][k].first;
					int cost = adj[j][k].second;

					if (mindist[nxt] > total + cost) { //3
						mindist[nxt] = total + cost;
						if (i == n - 1) flag = true;
					}
				}
			}
			if (flag) { printf("YES\n"); break; }
		}

		if (!flag) printf("NO\n");
	}

}
