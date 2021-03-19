#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
using namespace std;
#define INF 1e7
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

vector<int>s;

int n, m;
long long arr[100005];
int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	long long st = 0, en = 1000000000;
	while (st + 1 < en) {
		long long mid = (st + en) / 2;

		int cnt = 1;
		long long sum = 0;
		bool flag = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > mid) { flag = true; break; }
			if (sum + arr[i] > mid) { sum = arr[i]; cnt++; continue; }
			sum += arr[i];
		}

		if (cnt > m || flag) st = mid;
		else en = mid;
	}
	printf("%lld", en);
	
}
