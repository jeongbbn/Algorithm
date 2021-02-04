#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
typedef pair<string, bool>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int ans[1000005];
int now = 1;

int main() {
	int x = 1;
	while (now <= 1000000) {
		int cnt[10] = { 0, };
		bool flag = 0;

		int tmp = x;
		while (tmp != 0) {
			if (cnt[tmp % 10] >= 1) {
				flag = 1;
				break;
			}
			cnt[tmp % 10]++;
			tmp /= 10;
		}
		if (!flag) ans[now++] = x;
		x++;
	}

	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0) break;
		printf("%d\n", ans[n]);
	}
}
