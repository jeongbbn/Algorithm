#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define length 7

int arr[405][405];
int a[405][405], b[405][405], ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			a[i][j] = arr[i][j];
			b[i][j] = arr[i][j];
		}
	}

	for (int k = 1; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i + k >= n || j + k >= n) continue;
				a[i][j] += arr[i + k][j + k];
				b[i][j + k] += arr[i + k][j];
				ans = max(ans, a[i][j] - b[i][j + k]);
			}
		}
	}

	cout << ans;
}
