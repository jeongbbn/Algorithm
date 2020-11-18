#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int d[1005], arr[1005];
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	d[0] = 1;
	for (int i = 1; i < n; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && d[i] < d[j]+1) {
				d[i] = d[j] + 1;
			}
		}
	}
	printf("%d", *max_element(d, d + n));
}
