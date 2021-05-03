#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n;
priority_queue<int, vector<int>, greater<int>>pq;
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			int a;
			scanf("%d", &a);

			if (i == 0) pq.push(a);

			if (pq.top() < a) {
				pq.pop(); pq.push(a);
			}
		}
	}

	printf("%d", pq.top());
}
