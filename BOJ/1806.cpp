#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

long long arr[100005];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);

	
	int st = 0, en = 0;
	long long sum = 0;
	int minn = INF;

	while (1) {
		if (sum >= m) {
			minn = min(minn, en - st);
			sum -= arr[st];
			st++;
		}
		else if (en == n) break;
		else {
			sum += arr[en];
			en++;
		}
	}

	if (minn == INF) minn = 0;
	printf("%d", minn);

}
