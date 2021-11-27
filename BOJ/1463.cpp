#include <iostream>
#include <queue>
using namespace std;
int a;
bool visit[1000000];
queue<pair<int,int>>q;
void bfs(int k) {
	visit[k] = 1;
	q.push({ k,0 });
	while(!q.empty()){
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == 1) {
			printf("%d", cnt);
			return;
		}

		if (x % 3 == 0) {
			q.push({ x / 3, cnt + 1 });
			visit[x / 3] = 1;
		}
		if (x % 2 == 0) {
			q.push({ x / 2, cnt + 1 });
			visit[x / 2] = 1;
		}
		q.push({ x-1, cnt + 1 });
		visit[x-1] = 1;
	}
}
int main() {
	scanf("%d", &a);
	bfs(a);
}
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int a;
//int dp[1000000];
//
//int main() {
//	scanf("%d", &a);
//	dp[1] = 0;
//	for (int i = 2; i <= a; i++)
//	{
//		dp[i] = dp[i - 1] + 1;
//		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
//		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
//	}
//	printf("%d", dp[a]);
//}
