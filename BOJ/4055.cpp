#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

/*
5
1 4
2 3
2 3
2 4
2 4
*/
int n, day = 1;
int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		vector<pi>arr;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			arr.push_back({ a,b });
		}
		sort(arr.begin(), arr.end());

		priority_queue<int,
		for (int i = 0; i < n; i++)
		{
			int en = arr[i].second;
			int st = arr[i].first;

			if (p < st * 100) {
				p = st * 100 + 50;
				ans++;
			}
			else if (st * 100 <= p && p + 50 <= en * 100){
				p += 50;
				ans++;
			}
		}
		printf("On day %d ", day++);
		printf("Emma can attend as many as %d parties.\n", ans);
	}
}
