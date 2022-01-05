#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000000
typedef pair<string, bool>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, m, idx[105], ans;
char c;
string str, pattern;

//st: str의 현재 인덱스, p:pattern의 현재인덱스
void func(int st, int p, string s) {
	if (st == n) {//str를 다 돌았을 때
		if (s.length() != m) return; //s가 m이랑 다르다 <- 이게 없으면 B|_ BBBBB를 통과못함
		bool flag = 0; //_가 있나없나 확인

		if (ans != 2) { //단 한번이라도 ans=2가 되면, 이 값은 바뀌면 안된다.
			for (int i = 0; i < m; i++)
			{
				if (s[i] == '_') { flag = 1; c = pattern[i]; break; }
			}
		}
		if (!flag) ans = 2; //ABC==ABC라는 뜻
		else ans = 1; //A_C==ABC

		return;
	}

	//'('을 만난경우 (A|B|C) A,B,C 다 돌아봐야한다.
	if (str[st] == '(') {
		for (int i = st; i < idx[st]; i++)
		{
			if (idx[i] == 0) continue;
			func(i + 1, p, s);
		}
	}

	//'|'을 만난 경우엔 ')'로 이동한다
	else if (str[st] == '|') func(idx[st] + 1, p, s);

	//')'은 그냥 다음꺼 본다
	else if(str[st] == ')') func(st + 1, p, s);

	else {
		if (p == m) return; //st<n인데 p==m이란건, n>m란 소리
		if (str[st] == pattern[p] || str[st] == '_')
			func(st + 1, p + 1, s + str[st]);
	}

}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		cin >> str >> pattern;
		n = str.length();
		m = pattern.length();
		
		//')'과 연관된 애들('(','|'에게 idx[인덱스]=')'의 위치
		vector<int>v;
		for (int i = n - 1; i >= 0; i--)
		{
			if (str[i] == '(') { idx[i] = v.back(); v.pop_back(); }
			else if (str[i] == '|') idx[i] = v.back();
			else if (str[i] == ')') v.push_back(i);
		}

		func(0, 0, "");

		if (ans == 1) printf("%c\n", c);
		else if (ans == 0) printf("!\n");
		else printf("_\n");
		ans = 0; fill(idx, idx + 105, 0);
	}

}
