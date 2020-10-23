/*
 백준 20055 컨베이어 벨트 위의 로봇
 분류 : 구현
*/
#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n, k, N, en;
ll zero;
pi arr[305];
bool robot[305];
queue<int>q;

void rotate() {
	pi tmp = arr[N - 1];
	for (int i = N - 1; i > 0; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[0] = tmp;

	arr[en].second = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		if (arr[i].second == 1) q.push(i);
	}
}

void robotMove() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		int nx = x + 1;
		if (nx == N) nx = 0;
		if (arr[nx].first <= 0) continue;
		if (arr[nx].second == 1) continue;

		arr[nx].first--;
		arr[x].second = 0; arr[nx].second = 1;
		if (arr[nx].first == 0) zero++;
		if(nx == en) arr[nx].second = 0;
	}

	if (arr[0].first > 0 && arr[0].second != 1) {
		arr[0].first--;
		arr[0].second = 1;
		if (arr[0].first == 0) zero++;
	}
}

int main() {
	scanf("%d%d", &n, &k);
	N = 2 * n;
	en = n - 1;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i].first);

	int ans = 0;
	while (zero < k) {
		ans++;
		rotate();
		robotMove();
	}
	printf("%d", ans);
}
