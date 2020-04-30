#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
using namespace std;
#define INF 1e9+10

vector<int>ans;
long long arr[25],f[25];
bool check[25];
int main() {
	int n;
	scanf("%d", &n);
	
	f[0] = 1;
	for (int i = 1; i <= 20; i++)
		f[i] = i * f[i - 1];


	int nn;
	scanf("%d", &nn);
	if (nn == 1) {
		long long t;
		scanf("%lld", &t);

		int k = n - 1;
		for (int now = 0; now < n; now++)
		{
			for (int i = 1; i <= n; i++)
			{
				if (check[i]) continue;

				if (f[k] < t) {
					t -= f[k];
				}
				else {
					arr[now]=i;
					check[i] = 1;
					break;
				}
			}
			k--;
		}

		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
	}

	else {
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		int k = n - 1;
		long long ans = 0;
		for (int now = 0; now < n; now++)
		{
			for (int i = 1; i < arr[now]; i++)
			{
				if (check[i]) continue;
				ans += f[k];
			}
			k--;
			check[arr[now]] = 1;
		}
		printf("%lld", ans+1);

	}
}
