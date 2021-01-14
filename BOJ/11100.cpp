#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int arr[200005];
priority_queue<int, vector<int>, greater<int>>pq;
int main() {
	int n;
	scanf("%d", &n);

	vector<pi>time;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		time.push_back({ a, b });
	}
	sort(time.begin(),time.end());
	int maxx = -1;
	for (int i = 0; i < time.size(); i++)
	{
		while (!pq.empty() && pq.top() <= time[i].first) pq.pop();
		pq.push(time[i].second);
		int size = pq.size();

		maxx = max(size, maxx);
	}

	printf("%d", maxx);
}
