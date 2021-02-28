#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int>s;
	char str[31];
	scanf("%s", str);

	for (int i = 0; str[i]; i++)
	{
		int tmp = 0;
		if (!s.empty() && s.top() != -3 && s.top() != -2) {
			tmp += s.top();
			s.pop();
			s.push(tmp);
			tmp = 0;
		}

		switch (str[i]) {
		case '(': s.push(-2); break;
		case '[': s.push(-3); break;
		case ')':
			if (s.empty()) { printf("0"); return 0; }
			else {
				if (s.top() == -3) { printf("0"); return 0; }
				else if (s.top() == -2) { s.pop(); s.push(2); }
				else {
					while (1) {
						if (s.empty()) { printf("0"); return 0; }
						else if (s.top() == -3) { printf("0"); return 0; }
						else if (s.top() == -2) { s.pop(); break; }
						else {
							tmp += s.top() * 2;
							s.pop();
						}
					}
					s.push(tmp);
					tmp = 0;
				}
				break;
			}
		case ']':
			if (s.empty()) { printf("0"); return 0; }
			else {
				if (s.top() == -2) { printf("0"); return 0; }
				else if (s.top() == -3) {
					s.pop();
					s.push(3);
				}
				else {
					while (1) {
						if(s.empty()) { printf("0"); return 0; }
						else if (s.top() == -2) { printf("0"); return 0; }
						else if (s.top() == -3) { s.pop(); break; }
						else {
							tmp += s.top() * 3;
							s.pop();
						}
					}
					s.push(tmp);
					tmp = 0;
				}
			}
			break;
		}
	}
	if(s.empty()) { printf("0"); return 0; }
	int ans = 0;
	while (!s.empty()) {
		if(s.top()== -2 || s.top()==-3) { printf("0"); return 0; }
		ans += s.top();
		s.pop();
	}
	
	printf("%d", ans);
}
