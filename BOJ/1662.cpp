#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1'000'000'003
typedef unsigned long long ll;
typedef pair<char, int>pi;
typedef pair<int, pair<int, int>>pii;

string str;
stack<pi>s;
int arr[55];
int i, ans, cnt, p;

int main() {
	cin >> str;
	while (1) {
		if (i == str.size()) break;
		if (str[i] == ')') {
			cnt = 0;
			while (s.top().first != '(') {
				s.pop(); cnt++;
			}
			int now = s.top().second;
			if (now != p) {
				ans += (arr[p] + cnt); p--;
			}
			s.pop();
			int x = (s.top().first-'0'); s.pop();
			cnt *= x;
		}
		else {
			if (str[i] == '(') s.push({ str[i], p++ });
			else s.push({ str[i],0 });
		}
		i++; 
	}
	while (!s.empty()) { ans++; s.pop(); }
	printf("%d", ans);
}
