#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int main() {
	int n, a;
	scanf("%d", &n);

	vector<int>arr;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());
	int size = arr.size();
	if (size % 2 == 0) {
		int mid[2] = { size / 2 - 1,size / 2};
		int minn = INF, idx = 0;
		for (int j = 0; j < 2; j++)
		{
			int sum = 0;
			for (int i = 0; i < arr.size(); i++)
			{
				sum += abs(arr[i] - arr[mid[j]]);
			}
			if (minn > sum) {
				minn = sum;
				idx = arr[mid[j]];
			}
		}
		printf("%d", idx);
	}
	else {
		int sum = 0;
		int mid = size / 2;
		int minn = INF, idx = 0;

		for (int i = 0; i < arr.size(); i++)
		{
			sum += abs(arr[i] - arr[mid]);
		}
		if (minn > sum) {
			minn = sum;
			idx = arr[mid];
		}
		printf("%d", idx);
	}

	return 0;
}
