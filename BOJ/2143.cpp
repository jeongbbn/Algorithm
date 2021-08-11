#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pi;

ll ans, t, Apsum[1005], Bpsum[1005];
vector<ll>A, B;
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		Apsum[i + 1] = Apsum[i] + a;
	}

	for (int i = 0; i <= n; i++)
		for (int j = i+1; j <= n; j++)
			A.push_back(Apsum[j] - Apsum[i]);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		Bpsum[i + 1] = Bpsum[i] + a;
	}

	for (int i = 0; i <= m; i++)
		for (int j = i + 1; j <= m; j++)
			B.push_back(Bpsum[j] - Bpsum[i]);

	sort(B.begin(), B.end());

	for (int i = 0; i < A.size(); i++)
	{
		ll x = t - A[i];

		if (!binary_search(B.begin(), B.end(), x));

		int st = lower_bound(B.begin(), B.end(), x) - B.begin();
		int en = upper_bound(B.begin(), B.end(), x) - B.begin();

		ans += (en - st);
	}
	cout << ans;
}
