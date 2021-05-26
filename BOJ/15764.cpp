#include<bits/stdc++.h>
using namespace std;
#define INF 98765421
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, m, k, p;
vector<int>h, pos(105, -1);
vector<pi>chkin;
int done[105];
bool order[105];

int main() {
	cin >> n >> m >> k;
	h.resize(m + 1);
	for (int i = 0; i < m; i++) {
		cin >> h[i];
		pos[h[i]] = i;
	}

	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		done[a] = b; order[b] = 1;
		chkin.push_back({ b,a });
	}

	sort(chkin.begin(), chkin.end());

	int p = n;
	for (int i = m - 1; i >= 0; i--)
	{
		if (h[i] == 1) break;
		if (done[h[i]] != 0) continue;
		for (int j = k - 1; j >= 0; j--)
		{
			int x = chkin[j].second;
			if (pos[h[i]] < pos[x]) {
				p = chkin[j].first;
				break;
			}
		}

		for (int j = p; j >= 1; j--)
		{
			if (order[j]) continue;
			order[j] = 1; done[h[i]] = j;
			p = j - 1; break;
		}
	}

	p = 1;
	for (int i = 0; i < h.size(); i++)
	{
		if (done[h[i]] != 0) { p = done[h[i]]; continue; }
		for (int j = p; j <= n; j++)
		{
			if (order[j]) continue;
			order[j] = 1; done[h[i]] = j; break;
		}
	}

	if (done[1] == 0) {
		for (int j = 1; j <= n; j++)
		{
			if (order[j]) continue;
			order[j] = 1; done[1] = j; break;
		}
	}
	cout << done[1];
}
