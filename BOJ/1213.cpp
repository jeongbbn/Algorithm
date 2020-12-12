#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

string str;
int cnt[30];
vector<int>v;
int hol, p = -1;

int main() {
	cin >> str;
	int len = str.size();

	for (int i = 0; i < len; i++)
	{
		cnt[str[i] - 65]++;
	}

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < cnt[i]/2; j++)
		{
			v.push_back(i);
		}

		if (cnt[i] % 2 == 1) {
			hol++;
			p = i;
		}
	}

	if (hol > 1) printf("I'm Sorry Hansoo");

	else {
		for (int i = 0; i < v.size(); i++)
		{
			printf("%c", v[i] + 65);
		}
		if (p != -1) printf("%c", p + 65);
		reverse(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			printf("%c", v[i] + 65);
		}
	}
}
