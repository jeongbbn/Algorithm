#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<string>
#include <stack>
using namespace std;
#define INF 1e9+10
int main() {
	int n, m,arr[10005];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int st = 0, en = 0, cnt = 0, sum = 0;
	while(1) {
		if (sum >= m) {
			sum -= arr[st];
			st++;
		}
		else if (en == n) break;
		else {
			sum += arr[en];
			en++;
		}
		if (sum==m) cnt++;
	}
	printf("%d", cnt);
}
