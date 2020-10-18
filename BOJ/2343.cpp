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

int arr[100005];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	long long st = 0, en = 1000000000;
	while (st + 1 < en) {
		long long mid = (st + en) / 2;
		int cnt = 1;
		long long total = 0;

		bool flag = 0;
		for (int i = 0; i < n;)
		{
			total += arr[i];
			if (total > mid) {
				total = 0; cnt++;
				if (arr[i] > mid) { flag = 1; break; }
			}
			else i++;
		}

		if (cnt > m || flag)  st = mid;
		else en = mid;

	}
	printf("%lld", en);
}
