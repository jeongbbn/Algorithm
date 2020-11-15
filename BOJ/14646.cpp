#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef long long ll;
typedef pair<ll, ll>pi;
typedef pair<int, pair<int, int>>pii;

int n, now, ans;
bool sticker[100005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n * 2; i++)
	{
		int a;
		scanf("%d", &a);
		if (sticker[a]) {
			sticker[a] = 0;
			now--;
		}
		else {
			sticker[a] = 1;
			now++;
		}
		ans = max(ans, now);
	}
	printf("%d", ans);
}
