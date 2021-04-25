#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

int n;
bool check[25];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; int t;
		cin >> s;

		if (s == "add") {
			cin >> t;
			check[t] = 1;
		}
		else if (s == "check") {
			cin >> t;
			if (check[t]) printf("1\n");
			else printf("0\n");
		}
		else if (s == "remove") {
			cin >> t;
			check[t] = 0;
		}

		else if (s == "toggle") {
			cin >> t;
			if (check[t]) check[t] = 0;
			else check[t] = 1;
		}

		else if (s == "all") {
			for (int i = 1; i <= 20; i++)
			{
				check[i] = 1;
			}
		}

		else {
			for (int i = 1; i <= 20; i++)
			{
				check[i] = 0;
			}
		}
	}
}
