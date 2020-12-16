#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, ans;
int cnt[100005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		cnt[a]++; cnt[b]++;
	}

	printf("%d", *max_element(cnt, cnt + n) + 1);
}
