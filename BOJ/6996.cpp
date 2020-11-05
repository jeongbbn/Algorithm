#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int tc;
int main() {
	cin >> tc;
	while (tc--) {
		string A, B;
		cin >> A >> B;

		if (A.size() != B.size())
			cout << A << " & " << B << " are NOT anagrams.\n";
		else {
			string a, b;
			a = A; b = B;
			sort(a.begin(), a.end());
			sort(b.begin(), b.end());

			bool flag = 0;
			for (int i = 0; i < a.size(); i++)
			{
				if (a[i] != b[i]) {
					flag = 1;
					break;
				}
			}
			if (!flag) cout << A << " & " << B << " are anagrams.\n";
			else cout << A << " & " << B << " are NOT anagrams.\n";
		}
	}
}
