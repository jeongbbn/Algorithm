#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;

vector<int>adj[100005];
stack<int>s;
//dfsnumber			sccnumber
int dfsn[100005], sccNum[100005];
int dfscnt, scccnt;
//dfs순서	scc갯수
bool finished[100005];
//scc 추출 완료시 true

int dfs(int curr) {
	dfsn[curr] = ++dfscnt; //현재 보고있는 정점에 dfsn(부모)를 설정해줌
	s.push(curr);

	int result = dfsn[curr];
	for (int i = 0; i < adj[curr].size(); i++)
	{
		int nxt = adj[curr][i];

		//다음 정점 아직 방문 안함
		if (dfsn[nxt] == 0) result = min(dfs(nxt), result);
		//이미 방문했으나 scc 추출이 안끝난 상태 == 역방향 간선
		else if (!finished[nxt]) result = min(dfsn[nxt], result);
	}

	//돌고돌아 자기자신에게 도착 -> stack pop()
	if (result == dfsn[curr]) {
		while (1) {
			int t = s.top();
			s.pop();
			sccNum[t] = scccnt; // scc결과를 저장하는 배열에 그룹 넘버를 맵핑해줌
			finished[t] = true; //빼먹지 말자

			if (t == curr)break;
		}

		scccnt++;
	}
	return result;
}


void init() {
	dfscnt = 0;
	scccnt = 0;

	fill(dfsn, dfsn + 100005, 0);
	fill(finished, finished + 100005, 0);
	fill(sccNum, sccNum + 100005, 0);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, m;
		scanf("%d%d", &n, &m);

		init();
		for (int i = 1; i <= n; i++)
		{
			adj[i].clear();
		}

		for (int i = 0; i < m; i++)
		{
			int a,b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
		}

		for (int i = 1; i <= n; i++)
		{
			if (!dfsn[i]) {
				dfs(i);
			}
		}

		int indegree[100005] = { 0, };

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < adj[i].size(); j++)
			{
				int x = adj[i][j];
				if (sccNum[i] != sccNum[x]) indegree[sccNum[x]]++;
			}
		}

		int ans = 0;
		for (int i = 0; i < scccnt; i++)
		{
			if (indegree[i] == 0) ans++;
		}
		printf("%d\n", ans);


	}

}
