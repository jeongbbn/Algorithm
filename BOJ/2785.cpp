#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

int n, ans, remain; 
vector<int>v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n; v.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	remain = n - 1;
	for (int i = 1; i <= v.size(); i++)
	{
		if (v[i] < remain - 1) {
			remain -= v[i] + 1;
			ans += v[i];
		}
		else {
			ans += remain - 1;
			if (v[i] > remain - 1) ans++;
			break;
		}
	}
	cout << ans;
}
