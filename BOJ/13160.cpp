#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

vector<pi>arr,r;
int minn = INF, maxx = 0;
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		arr.push_back({ a,-1 }); //왼쪽이 -1이어야,
		arr.push_back({ b,1 }); //한 구간에서 시작점과 끝점이 겹칠 경우에도 올바르게 계산함
		r.push_back({ a,b });
	}

	sort(arr.begin(), arr.end());

	int cnt = 0, maxx = -1, line;
	for (int i = 0; i < 2*n; i++)
	{
		if (arr[i].second < 0) cnt++;
		else cnt--;

		if (maxx < cnt) {
			maxx = cnt;
			line = arr[i].first;
		}
	}

	printf("%d\n", maxx);

	//직접 그림을 그려보면 알 수 있다.
	for (int i = 0; i < n; i++)
	{
		if (r[i].second < line || r[i].first > line) continue;
		printf("%d ", i + 1);
	}
}
