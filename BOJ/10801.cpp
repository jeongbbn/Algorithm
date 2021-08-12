#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

int n, arr[2][15], a, b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int tc = 0; tc < 2; tc++)
	{
		for (int i = 0; i < 10; i++) {
			cin >> arr[tc][i];
		}
	}
	
	for (int i = 0; i < 10; i++) {
		if (arr[0][i] > arr[1][i]) a++;
		else if (arr[0][i] < arr[1][i]) b++;
	}

	if (a < b) cout << "B";
	else if (a == b) cout << "D";
	else cout << "A";
}
