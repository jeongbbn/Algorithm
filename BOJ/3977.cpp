#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100005

typedef pair<int, int> pi;
typedef pair<int, pair<int,int>> pii;

int n, m;
vector<int>adj[MAX];
int dfsn[MAX];
int sccNum[MAX],sccCnt, dfsCnt;
bool finished[MAX];
stack<int>s;

int dfs(int curr) {
	dfsn[curr] = ++dfsCnt;
	s.push(curr);

	int result = dfsn[curr];

	for (int nxt : adj[curr]) {

		if (dfsn[nxt] == 0) result = min(result, dfs(nxt));
		else if (!finished[nxt]) result = min(result, dfsn[nxt]);
	}

	if (result == dfsn[curr]) {

		while (1) {
			int t = s.top();
			s.pop();
			sccNum[t] = sccCnt;
			finished[t] = 1;
			if (t == curr) break;
		}
		sccCnt++;
	}
	return result;
}


void init() {
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		dfsn[i] = 0;
		sccNum[i] = 0;
		finished[i] = 0;
	}
	sccCnt = 0;
	dfsCnt = 0;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);

		init();
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);

			adj[a].push_back(b);
		}

		for (int i = 0; i < n; i++)
		{
			if (dfsn[i] == 0) dfs(i);
		}

		//scc 추출완료

		int indegree[MAX] = { 0, };
		//scc그래프 탐색
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < adj[i].size(); j++)
			{
				int nxt = adj[i][j];

				//다른 scc일 경우 indegree처리를 해준다.
				if (sccNum[i] != sccNum[nxt]) {
					//indegree[nxt]가 아니다! 이럴 경우
					// 2 0 1 0 2 3 0 3 3 4 4 5 5 3 이 경우
					// 2가 4 5 에는 안걸리게 된다.
					indegree[sccNum[nxt]]++;
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < sccCnt; i++)
		{
			if (indegree[i] == 0) ans++;
		}

		if (ans >= 2) printf("Confused\n");
		else {
			for (int i = 0; i < n; i++)
			{
				if (indegree[sccNum[i]] == 0) printf("%d\n", i);
			}
		}
		printf("\n");
	}
	
}
