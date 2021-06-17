#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<pair<int, int>, int>pii;
typedef long long ll;

int n, ans;
int arr[105], cnt[105];
vector<string>animal[105];


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string a;
		int k;
		
		cin >> a >> k;

		for (int j = 0; j < k; j++)
		{
			string str;
			cin >> str;
			animal[i].push_back(str);
		}
	}
	

	for (int i = 0; i < n; i++)
	{
		fill(cnt, cnt + n, 0);
		int size = animal[i].size();

		for (int k = 0; k < n; k++)
		{
			if (k == i) continue;

			for (int j = 0; j < size; j++)
			{
				string str1 = animal[i][j];

				for (int m = 0; m < animal[k].size(); m++)
				{
					string str2 = animal[k][m];
					if (str1 == str2) {
						cnt[k]++;
						break;
					}
				}
			}
		}
		
		ans = max(ans, *max_element(cnt, cnt + n) + 1);
	}
	printf("%d", ans);
}
