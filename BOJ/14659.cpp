#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

/*
시간복잡도 : O(n)

for문을 돌며, check point로 잡은 봉우리보다
낮은 봉우리들을 만나면 cnt++해준다.
그러다가 높은 봉우리를 만나면 check point를 바꿔주고
cnt를 다시 센다.

*/

int arr[30005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int p = arr[0], cnt = 0, maxx = -1;
	for (int i = 1; i < n; i++)
	{
		if(p < arr[i]) {
			p = arr[i];
			cnt = 0;
		}
		else cnt++;

		maxx = max(maxx, cnt);
	}

	printf("%d", maxx);
	return 0;
}
