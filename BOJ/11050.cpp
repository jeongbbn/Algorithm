#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pi;
#define mod 1000000007

int n, k, ans = 1;

int main() {
	cin >> n >> k;

	for (int i = 0; i < k; i++)
		ans *= n--;

	for (int i = 1; i <= k; i++)
		ans /= i;

	cout << ans;
}
