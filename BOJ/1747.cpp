#include <bits/stdc++.h>
using namespace std;
int n;

bool check(int x) {
	string str = to_string(x);

	int len = str.length();
	len -= 1;
	for (int i = 0; i <= len/2; i++)
	{
		if (str[i] != str[len - i]) return 0; 
	}
	return 1;
}


int main() {
	scanf("%d", &n);
	int ans = 2;
	for (int i = n; ; i++)
	{
		bool flag = 1;
		for (int j = 2; j*j <= i; j++)
		{
			if (i%j == 0) { flag = 0; break; }
		}
		if (flag && check(i) && i!=1) { ans = i; break; }
	}
	printf("%d", ans);
}
