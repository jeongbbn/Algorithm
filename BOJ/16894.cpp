#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
typedef pair<string, bool>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

ll n;
vector<ll>v;
bool loser; //0 : cube, 1 : koo

void func() {
	ll en = n;
	for (ll i = 2; i*i <= en; i++)
	{
		while (en % i == 0) {
			v.push_back(i);
			en /= i;
			if (v.size() == 2) return;
		}
	}
	if (en != 1) v.push_back(en);
	return;
}

int main() {
	cin >> n;
	func();
	if (v.size() == 2) {
		if (v[0] * v[1] == n) loser = 1;
	}

	if (loser) cout << "cubelover";
	else cout << "koosaga";
}
