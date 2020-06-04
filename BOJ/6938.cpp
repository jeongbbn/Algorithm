#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int arr[100005];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d.%d", &a, &b);
		arr[i] = a * 1000 + b*100;
	}

	sort(arr, arr + n);

	//절사평균
	int sum1 = 0;
	for (int i = k; i < n - k; i++)
	{
		sum1 += arr[i];
	}
	int ans1 = sum1 / (n - 2 * k);

	//보정평균
	for (int i = 0; i < k; i++)
		arr[i] = arr[k];

	for (int i = n-1; i >= n-k; i--)
		arr[i] = arr[n - k - 1];

	int sum2 = 0;
	for (int i = 0; i < n; i++)
		sum2 += arr[i];

	int ans2 = sum2 / n;

	if (ans1 % 10 >= 5) ans1 = ans1 / 10 + 1;
	else  ans1 = ans1 / 10;
	if (ans2 % 10 >= 5) ans2 = ans2 / 10 + 1;
	else ans2 = ans2 / 10;


	printf("%.2lf %.2lf", ans1/100.0, ans2/100.0);

}
