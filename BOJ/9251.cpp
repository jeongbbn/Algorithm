#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int n, m, k;
int arr[10][10];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
vector<pi>air;
queue<pi>q;
bool outrange(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>m - 1) return 1;
	return 0;
}

int dp[1005][1005];
int main() {
	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{

			if (s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	printf("%d", dp[s1.length()][s2.length()]);
}
