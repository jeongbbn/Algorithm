#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int n, m;
int maxx = -INF;
int arr[100005];
int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int st = 0, en = 0;
	int sum = 0;
	while (1) {
		if (en - st >= m) {
			sum -= arr[st++];
		}

		else if (en == n) break;

		else if (en - st < m) {
			sum += arr[en++];
		}

		if (en - st == m) {
			maxx = max(maxx, sum);

		}
	}

	printf("%d", maxx);
}
