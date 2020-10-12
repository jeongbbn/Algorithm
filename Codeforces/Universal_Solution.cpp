/*
Educational Codeforces Round 91 (Rated for Div. 2)
B. Universal Solution
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 1e9
typedef long long ll;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		string str, ans = "";
		cin >> str;

		int cnt[3] = { 0, };
		int len = str.length();

		for (int i = 0; i < len; i++)
		{
			if (str[i] == 'R') cnt[0]++;
			else if (str[i] == 'P') cnt[1]++;
			else cnt[2]++;
		}

		char chk = ' ';
		if (cnt[0] >= cnt[1] && cnt[0] >= cnt[2]) chk = 'P';
		else if (cnt[1] > cnt[0] && cnt[1] > cnt[2]) chk = 'S';
		else chk = 'R';

		for (int i = 0; i < len; i++)
		{
			printf("%c", chk);
		}
		printf("\n");
	}
}
