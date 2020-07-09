#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include <tuple>
#include<algorithm>
#include <string>
#include <stack>
using namespace std;
#define INF 1e9+10
int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	int n;
	scanf("%d ", &n);

	map<string, string,greater<string>>m;
	for (int i = 0; i < n; i++) {
		string name, stat;
		cin >> name >> stat;

		m[name] = stat;
	}

	map<string, string,greater<string>>::iterator iter;
	for (iter=m.begin(); iter!=m.end(); iter++)
	{
		if (iter->second == "enter")
			cout << iter->first <<"\n";
	}
}
