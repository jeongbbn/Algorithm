#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n, L, S;
string str;
int main() {
	scanf("%d", &n);
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'L')  L++;
	}
	S = n - L;

	int ans = S + L / 2 + 1;
	ans = min(ans, n);
	printf("%d", ans);
}
