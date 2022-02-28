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

int arr[10005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int maxx = *max_element(arr, arr + n);

	long long m;
	scanf("%lld", &m);

	int st = 1, en = maxx;
	while (st <= en) {
		int mid = (st + en) / 2;

		long long total = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] < mid) total += arr[i];
			else total += mid;
		}

		if (total <= m) st = mid+1;
		else en = mid-1;
	}
	printf("%d", en);

}
