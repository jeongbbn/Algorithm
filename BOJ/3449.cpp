#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n;
int main() {
	scanf("%d", &n);
	while (n--) {
		string a, b;
		cin >> a >> b;

		int ans = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i]) ans++;
		}
		printf("Hamming distance is %d.\n", ans);
	}
}
