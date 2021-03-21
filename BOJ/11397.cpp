#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

ll arr[4][5], w[2][5], tmp[4], res[4];
int n;

ll func(int x) {
	tmp[0] = arr[x][0];
	tmp[1] = arr[x][1] + 100;
	tmp[2] = (100 - min(arr[x][2], (ll)100)) * 100 + min(arr[x][2], (ll)100) * arr[x][3];
	tmp[3] = 100 + arr[x][4];

	return tmp[0] * tmp[1] * tmp[2] * tmp[3];
}

void sol(int x, int y) {
	ll a = res[x], b = res[y];

	if (a < b) printf("+\n");
	else if (a == b) printf("0\n");
	else printf("-\n");
}

int main() {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 5; j++)
			scanf("%lld", &arr[i][j]);

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 5; j++)
			scanf("%lld", &w[i][j]);

	for (int j = 0; j < 5; j++)
	{
		arr[2][j] = arr[0][j] - w[0][j] + w[1][j];
		arr[3][j] = arr[1][j] - w[1][j] + w[0][j];
	}

	for (int j = 0; j < 4; j++) res[j] = func(j);

	sol(0, 2);
	sol(1, 3);
}
