#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pi;

int n;
vector<int>ans, psum;
priority_queue <pi, vector<pi>> pq[2005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int c, s; cin >> c >> s;
		pq[s].push({ c, i });
	}

	ans.resize(n);
	psum.resize(n + 1);

	int sum = 0;
	for (int x = 1; x < 2005; x++)
	{
		pi bfr = { 0, 0 };
		int size = pq[x].size();

		while (!pq[x].empty()) {
			int color = pq[x].top().first;
			int idx = pq[x].top().second;
			pq[x].pop();

			if (bfr.first != color) {
				psum[bfr.first] += (x * bfr.second);
				bfr.second = 0;
				bfr.first = color;
			}
			ans[idx] = sum - psum[color];
			bfr.second++;
		}

		psum[bfr.first] += (x * bfr.second);
		sum += (x * size);
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}
