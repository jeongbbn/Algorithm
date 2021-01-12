#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int n, m,st,en,diff;
int arr[1000000];

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);

	int minn = INF;
	while (1) {
		if (diff == m) {
			printf("%d", diff);
			return 0;
		}

		if (diff > m) {
			st++;
			minn = min(minn, abs(diff - m));
		}
		else if (diff < m) {
			en++;
		}

		if (en == n) break;
		diff = arr[en] - arr[st];
	}

	printf("%d", m + minn);
}	
