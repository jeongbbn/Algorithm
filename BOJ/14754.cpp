#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, m;
bool chk[1005][1005];
int arr[1005][1005];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		int a, b, max = -1;
		for (int j = 0; j < m; j++) {
			if (max < arr[i][j]) {
				max = arr[i][j];
				a = i; b = j;
			}
		}
		chk[a][b] = 1;
	}

	for (int i = 0; i < m; i++) {
		int a, b, max = -1;
		for (int j = 0; j < n; j++) {
			if (max < arr[j][i]) {
				max = arr[j][i];
				a = i; b = j;
			}
		}
		chk[b][a] = 1;
	}

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j]) continue;
			ans += arr[i][j];
		}
	}

	printf("%lld", ans);
}
