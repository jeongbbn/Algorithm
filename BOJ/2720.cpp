#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 2e9

int tc, n, arr[] = { 25,10,5,1 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < 4; i++) {
			cout << n / arr[i] << " ";
			n %= arr[i];
		}
		cout << "\n";
	}
}
