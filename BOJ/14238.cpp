#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int t, chk[4];
int dp[55][55][55][3][3];
/*
	dp[a가 나온 횟수][b][c][prev][pprev] : 방문 유무
*/
string s;
bool endd = 0;

bool dfs(int a, int b, int c, int prev, int pprev, string str) {
	
	if (a == chk[0] && b == chk[1] && c == chk[2]) {
		cout << str;
		endd = 1;
		exit(0);
	}

	if (dp[a][b][c][prev][pprev]) return 0;
	//이전에 방문한 거 == 전에 해봤더니 안되더라
	dp[a][b][c][prev][pprev] = 1; //방문 체크의 의미&& 1이 계속 유지된다면? 별탈 없다는 뜻

	if (a + 1 <= chk[0]) { 
		if(dfs(a + 1, b, c, 0, prev, str + "A")) return 1; 
	}
	if (prev != 1 && b + 1 <= chk[1]) {
		if(dfs(a, b + 1, c, 1, prev, str + "B")) return 1;
	}
	if (pprev != 2 && prev !=2 && c + 1 <= chk[2]) {
		if(dfs(a, b, c + 1, 2, prev, str + "C")) return 1;
	}
	/*
		 만약 답을 찾으면 return 1이니까 끝나고
		 답을 못찾으면 다음 if문으로 가고
	*/
	return 0;
}

int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		chk[s[i] - 65]++;

	dfs(0, 0, 0, 3, 3, "");
	if (!endd) printf("-1");
}
