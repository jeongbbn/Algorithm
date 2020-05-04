#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int arr[1005][6];
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	int check[1005] = { 0, };

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			for (int k = 1; k < 6; k++)
			{
				if (arr[i][k] == arr[j][k]) {
					check[i]++;
					break;
				}
			}
		}
	}
	
	printf("%d", max_element(check + 1, check + n + 1) - check);
}
