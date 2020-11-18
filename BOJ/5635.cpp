/*
백준 5635 생일
2020.11.19
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, string> pi;

int n, tc, m;
vector<pi>v;
int main() {
	scanf("%d", &n);
	while (n--) {
		string arr[5];
		for (int i = 0; i < 4; i++)
		{
			cin >> arr[i];
			if (i != 0 && arr[i].size() == 1) arr[i] = "0" + arr[i];
		}
		v.push_back({ arr[3] + arr[2] + arr[1],arr[0] });
	}
	sort(v.begin(), v.end());
	cout << v.back().second << "\n";
	cout << v[0].second;
}
