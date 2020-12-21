#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;

int main() {
	int n;
	scanf("%d", &n);
	pi arr[55];
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}

	int rate[55];
	fill(rate, rate + 55, 1);
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i].first > arr[j].first && arr[i].second > arr[j].second) rate[j]++;
			else if (arr[i].first < arr[j].first && arr[i].second < arr[j].second) rate[i]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", rate[i]);
	}
}
