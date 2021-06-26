#include<bits/stdc++.h>
using namespace std;
int n, p, a, b;
string A, B;
map<string, int>m;
vector<int>adj[1005], timetable(1005, -1);

bool gototop(int x, int cnt) {
	if (timetable[x] != -1) {
		a = timetable[x];
		b = cnt;
		return 1;
	}

	timetable[x] = cnt;

	if (adj[x].empty()) return 0;
	return gototop(adj[x][0], cnt + 1);
}

int main() {

	cin >> n >> A >> B;
	m[A] = p++; m[B] = p++;

	while (n--) {
		string a, b;
		cin >> a >> b;
		if (m.find(a) == m.end()) m[a] = p++;
		if (m.find(b) == m.end()) m[b] = p++;
		adj[m[b]].push_back(m[a]);
	}

	gototop(m[A], 0);

	if (!gototop(m[B], 0)) cout << "NOT RELATED";

	else {
		if (b > a) { swap(a, b); B.swap(A); }

		if (b == 0) {
			if (a == 1) cout << B << " is the mother of " << A;
			else {
				cout << B << " is the ";
				for (int i = 2; i < a; i++) printf("great-");
				cout << "grand-mother of " << A;
			}
		}

		else if (b == 1) {
			if (a == 1) cout << "SIBLINGS";
			else {
				cout << B << " is the ";
				for (int i = 2; i < a; i++) printf("great-");
				cout << "aunt of " << A;
			}
		}

		else cout << "COUSINS";
	}
}
