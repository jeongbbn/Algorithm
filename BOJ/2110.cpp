#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
#define INF 800*1000
typedef pair<int, int>pii;
int main() {
	int n, c, arr[200005];

	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	long long st = 0, en = 1000000000;
	while (st + 1 < en) {
		long long mid = (st + en) / 2;

		int prev = 0, cnt = 1;
		for (int i = 1; i < n; i++)
		{
			if (arr[i] - arr[prev] >= mid) {
				cnt++;
				prev = i;
			}
		}
		if (cnt >= c) st = mid;
		else en = mid;
	}
	printf("%lld", st);
}
