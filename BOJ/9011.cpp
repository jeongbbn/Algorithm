#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, arr[105] = { 0, };
		vector<int>ans;

		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 1; i <= n; i++) pq.push(i);

		bool flag = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			int x = arr[i];
			queue<int>q;

			while (x-- && !pq.empty()) { q.push(pq.top()); pq.pop(); }
			if (pq.empty()) { flag = 1; break;}
			ans.push_back(pq.top());
			pq.pop();

			int size = q.size();
			for (int j = 0; j < size; j++)
			{
				pq.push(q.front());
				q.pop();
			}
		}
	
		if (flag) printf("IMPOSSIBLE");
		else for (int i = n-1; i >= 0; i--) printf("%d ", ans[i]);
		printf("\n");
	}

}
