#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include <string>
#include <stack>
using namespace std;
#define INF 1e9+10
int main() {
	int n;
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {
		stack<char>ss;
		string s;
		getline(cin,s);
		for (int i = 0; i < s.length()+1; i++)
		{
			if (s[i] == ' ' || s[i]=='\0') {
				while (!ss.empty()) {
					char tmp = ss.top();
					ss.pop();
					printf("%c", tmp);
				}
				printf(" ");
			}
			else ss.push(s[i]);
		}
		printf("\n");
	}
}
