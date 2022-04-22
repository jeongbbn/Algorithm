#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;

int main() {
	string str, bang;
	cin >> str >> bang;

	stack<char>s;
	int len = str.length(); 
	int blen = bang.length(); //폭발 문자열

	string tmp;

	for (int i = len-1; i >= 0; i--)
	{
		int flag = 0;
		tmp += str[i]; //tmp에 일단 문자열을 넣음
		s.push(str[i]);
		int tmplen = tmp.length();

		for (int k = 0, j = blen - 1; k < tmplen; k++, j--)
		{
			if (tmp[k] != bang[j]) { flag = 0; break; }
			flag++;
		}
		if (flag == 0) { //0이라는건 폭발 문자열이 포함되지않았다는 뜻
			string tmp2 = "";
			for (int k = 1; k < tmplen; k++) tmp2+=tmp[k];
			tmp = tmp2; //글자 하나를 지워준다
		}

		else if (flag == blen) { //폭발 문자열이 있을 경우
			while (flag--) s.pop();  //폭발문자열만큼 지워줌
			string tmp2 = "";
			tmp = "";
			int k = blen - 1;
			while (!s.empty() && k--) { tmp2 += s.top(); s.pop(); } //남은 글자를 다시 채워줌
			int tmplen = tmp2.length();
			for (int i = tmplen - 1; i >= 0; i--) { s.push(tmp2[i]); tmp += tmp2[i]; }
			//문자열을 뒤집어서 저장해줘야한다.
		}
	}

	vector<char>ans;
	while (!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}

	if (ans.empty()) printf("FRULA");
	else {
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%c", ans[i]);
		}
	}
}
