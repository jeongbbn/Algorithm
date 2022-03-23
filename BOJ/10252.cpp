#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int dp[1005], arr[1005];

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, m;
		scanf("%d%d", &n, &m);

		printf("1\n");
		if (m % 2 == 0) {
			//오
			for (int i = 0; i < m; i++)
			{
				if (i % 2 == 0) {
					//위
					for (int j = n - 2; j >= 0; j--)
					{
						printf("(%d,%d)\n", j, i);
					}
				}
				else {
					//아래
					for (int j = 0; j < n-1; j++)
					{
						printf("(%d,%d)\n", j, i);
					}
				}
			}

		}
		else {
			for (int i = 0; i < m; i++)
			{
				if (i % 2 == 0) {
					//아래
					for (int j = 0; j < n - 1; j++)
					{
						printf("(%d,%d)\n", j, i);
					}
					
				}
				else {
					//위
					for (int j = n - 2; j >= 0; j--)
					{
						printf("(%d,%d)\n", j, i);
					}
				}
			}
		}

		for (int j = m - 1; j >= 0; j--)
		{
			printf("(%d,%d)\n",n - 1, j);
		}
	}
}
