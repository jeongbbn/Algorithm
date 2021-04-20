#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
#include <math.h>
using namespace std;
#define INF 2e9+1
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int arr[100005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int st = 0, en = n - 1, dist = INF;
	int ans[3] = { 0, };

	while (st < en) {
		if (abs(arr[st] + arr[en]) < dist) {
			dist = abs(arr[st] + arr[en]);
			ans[0] = arr[st];
			ans[1] = arr[en];
		}

		if (arr[st] + arr[en] == 0) break;
		else if (arr[st] + arr[en] < 0) st++;
		else en--;
	}
	printf("%d", ans[1] + ans[0]);
}
