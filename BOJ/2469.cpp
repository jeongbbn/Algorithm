#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

char str2[30], str1[30];
char ladder[1005][30];

int main() {
	int k, n;
	scanf("%d%d", &k, &n);
	scanf("%s", str2);
	for (int i = 0; i < k; i++)
	{
		str1[i] = 65 + i;
	}

	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", ladder[i]);
		if (ladder[i][0] == '?') flag = i;
	}

	for (int i = 0; i < flag; i++)
	{
		for (int j = 0; j < k-1; j++)
		{
			if (ladder[i][j] == '-') {
				char tmp = str1[j];
				str1[j] = str1[j+1];
				str1[j+1] = tmp;
			}
		}
	}

	for (int i = n-1; i > flag; i--)
	{
		for (int j = 0; j < k - 1; j++)
		{
			if (ladder[i][j] == '-') {
				char tmp = str2[j];
				str2[j] = str2[j + 1];
				str2[j + 1] = tmp;
			}
		}
	}

	vector<char>ans;
	for (int i = 0; i < k-1; i++)
	{
		if (str1[i] == str2[i]) ans.push_back('*');
		else if (str1[i] == str2[i + 1] && str1[i + 1] == str2[i]) {
			ans.push_back('-');
			i++;
			if (i == k-1) continue;
			ans.push_back('*');
		}
		else {
			for (int j = 0; j < k-1; j++)
				printf("x");

			return 0 ;
		}
	}
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%c", ans[i]);
	}

}
