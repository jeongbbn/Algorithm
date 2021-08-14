#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pi;
typedef pair<ll, pi>pii;
#define INF 1e12

int N, M, K;
vector<pi>adj[10005];
ll mindist[10005][25];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= 20; j++)
			mindist[i][j] = INF;

	mindist[1][0] = 0;
	pq.push({ 0,{1,0} });

	while (!pq.empty()) {
		ll dist = pq.top().first;
		ll x = pq.top().second.first;
		ll cnt = pq.top().second.second;
		pq.pop();

		if (mindist[x][cnt] != dist) continue;

		for (int i = 0; i < adj[x].size(); i++)
		{
			ll nxt = adj[x][i].first;
			ll cost = adj[x][i].second;

			if (mindist[nxt][cnt] > dist + cost) {
				mindist[nxt][cnt] = dist + cost;
				pq.push({ dist + cost, {nxt, cnt} });
			}

			if (cnt + 1 <= K && mindist[nxt][cnt + 1] > dist) {
				mindist[nxt][cnt + 1] = dist;
				pq.push({ dist, {nxt, cnt + 1} });
			}
		}
	}

	cout << *min_element(mindist[N], mindist[N] + K + 1) ;
	return 0;
}
