#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n;
vector<string>v;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		char *res;
		res = strtok((char *)str.c_str(), "-");

		while (res != NULL) {
			string tmp;
			tmp += res;
			res = strtok(NULL, "-");
			v.push_back(tmp);
		}
	}

	for (int i = 0; i < v.size(); i+=2)
	{
		int sumA = 0; int digit = 1;
		for (int j = (int)v[i].size() - 1; j >= 0; j--)
		{
			if (v[i][j] >= 'A' && v[i][j] <= 'Z') {
				sumA += (v[i][j] - 'A') * digit;
			}
			else {
				sumA += (v[i][j] - 'a') * digit;
			}
			digit *= 26;
		}

		int sumB = stoi(v[i + 1]);

		if (abs(sumA - sumB) <= 100) printf("nice\n");
		else printf("not nice\n");
	}
}	
