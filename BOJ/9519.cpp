#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
#define INF 800*1000
typedef pair<int, int>pii;

vector<char> blink(vector<char> tmp) {
	int len = tmp.size();
	vector<char>ans;
	for (int i = 0; i < len; i+=2)
		ans.push_back(tmp[i]);
	if (len % 2 == 1) len = len - 1;
	for (int i = len-1; i >= 0; i-=2)
		ans.push_back(tmp[i]);
	return ans;
}

int main() {
	long long n; 
	char str[1005];
	scanf("%lld", &n);
	scanf("%s", str);

	vector<char>input;
	for (int i = 0; str[i] != '\0'; i++) {
		input.push_back(str[i]);
	}

	long long repeat=0;
	while (1) {
		input = blink(input);
		repeat++;
		bool flag = false;
		for (int i = 0; str[i] != '\0'; i++) {
			if (input[i] != str[i]) { flag = true; break; }
		}
		if (!flag) break;
	}

	n = n % repeat;
	for (long long i = 0; i < n; i++) {
		input = blink(input);
	}

	for (int i = 0; i < input.size(); i++)
		printf("%c", input[i]);
	printf("\n");

} 
