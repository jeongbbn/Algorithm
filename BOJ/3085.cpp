#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n, ans;
char arr[55][55];
int find() {
	int returnn = 0;
	int tmp1;
	for (int j = 0; j < n; j++)
	{
		tmp1 = 1;
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i][j] == arr[i + 1][j]) {
				tmp1++;
			}
			else {
				returnn = max(tmp1, returnn);
				tmp1 = 1;
			}
			returnn = max(tmp1, returnn);
		}
	}

	for (int j = 0; j < n; j++)
	{
		tmp1 = 1;
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[j][i] == arr[j][i+1]) {
				tmp1++;
			}
			else {
				returnn = max(tmp1, returnn);
				tmp1 = 1;
			}
			returnn = max(tmp1, returnn);
		}
	}
	return max(returnn, tmp1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf(" %c", &arr[i][j]);
		}
	}
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != n - 1) {
				if (arr[i][j] != arr[i + 1][j]) {
					swap(arr[i][j], arr[i + 1][j]);
					ans = max(find(), ans);
					swap(arr[i][j], arr[i + 1][j]);
				}
			}
			if (j != n - 1) {
				if (arr[i][j] != arr[i][j + 1]) {
					swap(arr[i][j], arr[i][j + 1]);
					ans = max(find(), ans);
					swap(arr[i][j], arr[i][j + 1]);
				}
			}
		}
	}
	printf("%d", ans);
}
