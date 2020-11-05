#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

int n, a, b;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char c;
		scanf(" %c", &c);
		if (c == 'A') a++;
		else b++;
	}
	if (a > b) printf("A");
	else if (a < b) printf("B");
	else printf("Tie");
}
