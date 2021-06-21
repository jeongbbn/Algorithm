#include <bits/stdc++.h>
using namespace std;
#define INF 1e12
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

ll n;
vector<int>v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	
	if (n % 2 == 0) cout << v[n / 2 - 1];
	else cout << v[n / 2];
}
