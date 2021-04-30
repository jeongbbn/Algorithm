#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

int tc, n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> tc;
	while (tc--) {
		cin >> n;
		deque<char>dq;

		for (int i = 0; i < n; i++)
		{
			char c; cin >> c;
			if (dq.empty()) dq.push_back(c);
			else {
				if (dq.front() >= c) dq.push_front(c);
				else dq.push_back(c);
			}
		}

		for (int i = 0; i < n; i++)
		{
			cout << dq.front();
			dq.pop_front();
		}
		cout << "\n";
	}
}
