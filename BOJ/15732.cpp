#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int arr[10005][3];
int main() {
	int n,k,d;
	scanf("%d%d%d", &n, &k,&d);

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	int st = 0, en = 200;
	while (st + 1 < en) {
		int mid = (st + en) / 2;

		long long cnt = 0;
		for (int i = 0; i < k; i++)
		{
			if (arr[i][0] <= mid)
				cnt += (min(mid,arr[i][1]) - arr[i][0]) / arr[i][2] + 1;
		}

		if (cnt >= d) en = mid;
		else st = mid;
	}

	printf("%d", en);

}
