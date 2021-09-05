#include <iostream>
#include <queue>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;

int v, e, st;
vector<pi>adj[20005]; // adj[1] = {2,3} : 1에서 2로 가는, 가중치가 3인 간선
vector<int>mindist;
priority_queue<pi, vector<pi>, greater<pi>>pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	//boj input---------------
	//cin >> v >> e;
	//cin >> st;

	//for (int i = 0; i < e; i++)
	//{
	//	int a, b, c;
	//	cin >> a >> b >> c;
	//	adj[a].push_back({ b, c });
	//}
	


	//input - ppt graph
	v = 5; e = 7; 
	st = 1;
	adj[1].push_back({ 2,2 });
	adj[1].push_back({ 3,6 });
	adj[2].push_back({ 3,4 });
	adj[2].push_back({ 4,5 });
	adj[3].push_back({ 4,6 });
	adj[3].push_back({ 5,3 });
	adj[4].push_back({ 5,10 });


	//Initialize the mindist table
	mindist.resize(v + 1);
	for (int i = 1; i <= v; i++) mindist[i] = INF;


	//Set the starting point
	mindist[st] = 0;
	pq.push({ 0, st }); //pq에 {cost, node} 꼴로 넣어준다.


	//dijkstra
	while (!pq.empty()) {
		int dist = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (mindist[x] != dist) continue;

		for (int i = 0; i < adj[x].size(); i++)
		{
			int nxt = adj[x][i].first;
			int cost = adj[x][i].second;

			//key point!
			if (dist + cost < mindist[nxt]) {
				mindist[nxt] = dist + cost;
				pq.push({ mindist[nxt], nxt });
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (mindist[i] == INF) cout << "INF\n";
		else cout << mindist[i] << "\n";
	}
}
