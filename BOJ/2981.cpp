#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	int n, arr[105];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);
	vector<int>diff;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			diff.push_back(abs(arr[i] - arr[j]));
		}
	}

	vector<int>ans;
	int size = diff.size();
	int GCD = diff[0];
	for (int i = 0; i < size - 1; i++)
	{
		GCD = gcd(GCD, diff[i + 1]);
	}

	for (int i = 1; i*i <= GCD; i++)
	{
		if (GCD % i != 0) continue;

		ans.push_back(GCD / i);
		if (GCD / i == i || i == 1) continue;
		ans.push_back(i);
	}
		
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}
}
