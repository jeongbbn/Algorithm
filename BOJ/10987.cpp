#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int cnt;
string str;
int main() {
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		char &k = str[i];
		if (k == 'a' || k == 'e' || k == 'i' || k == 'u' || k == 'o') cnt++;
	}
	printf("%d", cnt);
}
