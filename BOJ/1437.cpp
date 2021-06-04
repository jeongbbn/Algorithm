#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	ll sum = 1;

	while (n >= 5) {
		sum = (sum * 3) % mod;
		n -= 3;
	}
	sum = (sum * n) % mod;

	cout << sum;
}
