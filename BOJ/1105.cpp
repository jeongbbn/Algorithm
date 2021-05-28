#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<string, string>pi;
typedef pair<int, pi>pii;

int ans;
string a, b;
vector<int>v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;

	int diff = b.length() - a.length();
	for (int i = 0; i < b.size(); i++)
	{
		int a_pos = i - diff;
		if (a_pos < 0) break;
		if (b[i] == a[a_pos]) {
			if (a[a_pos] == '8') ans++;
		}
		else break;
	}
	cout << ans;
}
