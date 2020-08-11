#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<string>
#include <stack>
using namespace std;
#define INF 1e9+10
typedef pair<int, pair<int, int>>pp;

stack<char>s;
queue<char>q;
int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	string str;
	getline(cin, str);
	bool flag = 0;
	for (int i = 0; i < str.length()+1; i++)
	{
		if (flag) {
			q.push(str[i]);
			if (str[i] == '>') {
				while (!q.empty()) {
					cout << q.front();
					q.pop();
				}
				flag = 0;
			}
			continue;
		}
		if (str[i] == ' ' || str[i]=='\0') {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			cout << ' ';
		}
		else if (str[i] == '<') { 
			flag = 1; 
			q.push(str[i]); 
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
		}
		else s.push(str[i]);

	}
}
