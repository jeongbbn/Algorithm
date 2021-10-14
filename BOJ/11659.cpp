#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, m, k;
int arr[100005];
int prefix[100010];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);

		prefix[i + 1] = prefix[i] + a;
	}
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", prefix[b] - prefix[a-1]);
	}
}
