#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
priority_queue<int, vector<int>, greater<int>> maxx;
priority_queue<int> minn;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;

		if (minn.size() == maxx.size()) minn.push(a); 
		else maxx.push(a);

		if (!minn.empty() && !maxx.empty()) {
			if (minn.top() > maxx.top()) {
				int a = minn.top();
				int b = maxx.top();
				minn.pop(); maxx.pop();

				minn.push(b);
				maxx.push(a);
			}
		}

		cout << minn.top() << "\n";
	}
}
