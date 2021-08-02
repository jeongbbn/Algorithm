#include<bits/stdc++.h>
using namespace std;

string str[3];
int chk[4][30];
set<string> ans1, ans2;

void find(int k) {
	string tmp = "";
	for (int i = 0; i < 26; i++)
	{
		if (chk[k][i] > 0) tmp += (i + 65);
		chk[k][i] = 0;
	}
	if (tmp.size() == 2) ans2.insert(tmp);
	else if (tmp.size() == 1) ans1.insert(tmp);
}

int main() {
	for (int i = 0; i < 3; i++) cin >> str[i];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			chk[0][str[i][j] - 65]++;
			chk[1][str[j][i] - 65]++;
		}
		find(0); find(1);
	}

	chk[2][str[0][0] - 65]++; chk[2][str[1][1] - 65]++; chk[2][str[2][2] - 65]++;
	chk[3][str[2][0] - 65]++; chk[3][str[1][1] - 65]++; chk[3][str[0][2] - 65]++;

	find(2); find(3);

	cout << ans1.size() << "\n" << ans2.size();
}
