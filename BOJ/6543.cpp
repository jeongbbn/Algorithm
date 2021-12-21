#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 5005
typedef pair<int, int>pi;


int dfsn[MAX];
int sccNum[MAX];
bool finished[MAX];
int dfscnt, sccCnt, n;
stack<int>s;
vector<int>adj[MAX];

void init() {
	memset(finished, 0, sizeof(finished));
	memset(dfsn, 0, sizeof(dfsn));
	memset(sccNum, 0, sizeof(sccNum));
	dfscnt = 0;
	sccCnt = 0;
	for (int i = 0; i < MAX; i++)
	{
		adj[i].clear();
	}

}

int dfs(int curr) {
	dfsn[curr] = ++dfscnt;
	s.push(curr);

	int result = dfsn[curr];
	for (int i = 0; i < adj[curr].size(); i++)
	{
		int nxt = adj[curr][i];

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

int main() {
	while (1) {
		int m;
		scanf("%d", &n);
		if (n == 0) break;

		init();

		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);	
			adj[a].push_back(b);
		}

		for (int i = 1; i <= n; i++)
		{
			if (dfsn[i] == 0) dfs(i);
		}
		//scc 추출 완료
		bool check[MAX] = { 0, };
		int outdegree[MAX] = { 0, };
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < adj[i].size(); j++)
			{
				int nxt = adj[i][j];
				if (sccNum[nxt] != sccNum[i]) {
					outdegree[i]++;
					check[sccNum[i]] = 1; //outdegree가 있는 SCC를 없애주기 위함
				}
			}
		}

		vector<int>ans;
		for (int i = 1; i <= n; i++)
		{
			if (outdegree[i] == 0 && !check[sccNum[i]]) ans.push_back(i);
		}

		sort(ans.begin(), ans.end());

		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
}
