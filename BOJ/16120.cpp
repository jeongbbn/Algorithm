#include<iostream>
#include<vector>
#include<queue>
#include <tuple>
#include<algorithm>
#include<set>
#include<map>
#include <string>
using namespace std;
#define INF 1e7
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

char str[1'000'005];
int cnt = 0;
int main() {
	scanf("%s", str);

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == 'P') { cnt++; continue; }

		if (str[i] == 'A') { 
			if (cnt < 2) { printf("NP\n"); return 0; } 
			if (str[i + 1] == '\0') { printf("NP\n"); return 0; } 
			if (str[i + 1] == 'A') { printf("NP\n"); return 0; } 
			cnt -= 2;
		}
	}
	if(cnt==1) printf("PPAP\n");
	else printf("NP\n");
	return 0;
}
