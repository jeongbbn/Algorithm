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

int arr[105];
int d[10005];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int j = 0; j <= k; j++) {
		d[j] = INF;
	}
	for (int i = 0; i <= k; i += arr[0])
	{
		d[i] = i / arr[0];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if(j-arr[i]>=0)
				d[j] = min(d[j - arr[i]] + 1, d[j]);
		}
	}
	if (d[k] == INF) printf("-1");
	else printf("%d", d[k]);
}
