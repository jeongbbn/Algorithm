#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int n, l, p, ans, idx;
vector<pi> arr;
priority_queue<int, vector<int>>pq;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr.push_back({ a,b });
	}
	scanf("%d%d", &l, &p);
	arr.push_back({ l,0 });
	sort(arr.begin(), arr.end());

	int fuel = p;
	while (idx < n + 1) {
		if (arr[idx].first > fuel) {
			while (!pq.empty() && arr[idx].first > fuel) {
				fuel += pq.top();
				pq.pop(); ans++;
			}
			if (pq.empty() && arr[idx].first > fuel) {
				ans = -1; break;
			}
		}
		else {
			pq.push(arr[idx++].second);
		}
	}
	printf("%d", ans);
	
	return 0;
}
