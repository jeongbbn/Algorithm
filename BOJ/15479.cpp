#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
map<string, string> m;
map<string, int> c;
map<string, vector<string>> v;

int go(string A, string B) {
	if (A == B) return 0;
	if (m[A].empty()) return -1e9;
	return go(m[A], B) + 1;
}

void go2(string BE, string EL) {
	if (m[BE] == m[EL]) {
		cout << "SIBLINGS" << '\n';
		exit(0);
	}

	int parent = go(m[BE], EL);
	if (parent > -1) {
		cout << EL << " is the ";
		for (int i = 0; i < parent - 1; i++) {
			cout << "great-";
		}
		if (parent > 0) {
			cout << "grand-";
		}
		cout << "mother of " << BE << '\n';
		exit(0);
	}

	parent = go(m[BE], m[EL]);
	if (parent > -1) {
		cout << EL << " is the ";
		for (int i = 0; i < parent - 1; i++) {
			cout << "great-";
		}
		cout << "aunt of " << BE << '\n';
		exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	string BE, EL;
	cin >> BE >> EL;
	for (int i = 0; i < n; i++) {
		string A, B;
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
		m[B] = A;
	}

	if (m[BE].empty() && m[EL].empty()) {
		cout << "NOT RELATED" << '\n';
		return 0;
	}
	go2(BE, EL);
	// go2(EL, BE);

	queue<string> q;
	q.push(BE);
	c[BE] = 1;

	while (!q.empty()) {
		string x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			string y = v[x][i];
			if (c[y] != 0) continue;
			c[y] = 1;
			q.push(y);
		}
	}

	if (c[EL] == 1) {
		cout << "COUSINS" << '\n';
		return 0;
	}

	cout << "NOT RELATED" << '\n';
}
