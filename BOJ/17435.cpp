#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pi;
#define INF 1e9 + 7

int m, s[200005][20], q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m;

	// s[i][j] = 정점 i에서 2^j번 이동한 후의 정점
	// f(1), f(2), f(3), ...
	for (int i = 1; i <= m; i++)
		cin >> s[i][0];
	
	for (int j = 1; j < 20; j++)
		for (int i = 1; i <= m; i++)
			s[i][j] = s[s[i][j - 1]][j - 1];
	/*
		j=1이면, 2^1번 이동한 후의 정점이다.
		f(f(1)) = f(3) = 5 -> s[1][1] = s[s[1][0]][0] == s[3][0] == 5

		j=2이면, 2^2번 이동한 후의 정점이다.
		f(f(f(f(1)))) = f(f(f(3))) = f(f(5)) <- f(f(5)) == s[5][1]
		-> s[1][2] = s[s[1][1]][1] = s[5][1]
	*/
	
	cin >> q;
	while (q--) {
		int n, x; 
		cin >> n >> x;
		/*
			n=13 -> 1101 => 1+4+8 
			s[x][1] => s[s[x][1]][4] => s[s[s[x][1]][4]][8]

			n이 있을 때, 몇 번째 비트가 켜져있는지 확인하고 싶다면,
			n & (1 << i)을 활용하자.
		*/
		for (int i = 19; i >= 0; i--)
		{
			if (n & (1 << i)) {
				x = s[x][i];
			}
		}
		cout << x << "\n";
	}
}
