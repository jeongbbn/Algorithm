#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

int n, k, sum;
vector<string>v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	cout << v[0];
	sum = v[0].length();
	for (int i = 1; i < n; i++)
	{
		if (sum + v[i].length() > k) {
			cout << "\n" << v[i];
			sum = v[i].length();
		}
		else {
			sum += v[i].length();
			cout << " " << v[i];
		}
	}
}
