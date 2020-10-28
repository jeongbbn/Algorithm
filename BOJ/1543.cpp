#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<map>
#include <string>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

string docu, word;
int main() {
	getline(cin, docu);
	getline(cin, word);

	int docuLen = docu.length();
	int wordLen = word.length();

	int cnt = 0;
	int i = 0;
	while (1) {
		if (i > docuLen) break;
	
		bool flag = false; int widx = 0;
		for (int j = i; widx < wordLen; j++, widx++)
		{
			if (word[widx] != docu[j]) { flag = true; break; }
		}
		if (!flag) {
			cnt++; i = i + wordLen;
		}
		else i++;
	}

	printf("%d", cnt);
}
