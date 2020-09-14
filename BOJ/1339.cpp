#include <bits/stdc++.h>
using namespace std;

int n, ABC[30]; //ABC[65], ABC[67] .. 어떤 알파벳이 나왔는지 저장하기 위함
bool visit[15];
vector<int>d[15]; //자릿수에 맞는 애들을 넣어주기위한 배열
//d[1][] : 일의 자리 숫자들, d[2][] : 십의 자리 숫자들 ..
vector<int>indexx; //ABC를 위해 사용할 인덱스 맵핑 배열(index[0]=65 ...)
int key[15], maxx = -1;

/*
백트래킹
1. pow()는 생각보다 오래걸린다. 시간초과가 났었는데 pow 때문이었다.
2. 수학을 이용해서도 풀 수 있다. 
*/

void P(int k) {
	if (k == n) {
		int sum = 0;
		int ten = 1;
		for (int i = 1; i <= 8; i++)
		{
			if (d[i].size() == 0)	break;
			for (int j = 0; j < d[i].size(); j++)
			{
				int x = d[i][j];
				sum += ABC[x] * ten;
			}
			ten *= 10; //pow 함수 대신 사용
		}
		maxx = max(sum, maxx);

		return;
	}

	for (int i = 9; i > (9-n); i--)
	{
		if (visit[i]) continue;
		visit[i] = 1;
		ABC[indexx[k]] = i;
		P(k + 1);
		visit[i] = 0;
	}
}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		char str[10];
		scanf("%s", str);

		int len = strlen(str);
		for (int j = 0; j < len; j++)
		{
			//알파벳이 처음 나왔으면, indexx 맵핑해줌
			if (ABC[str[j] - 64] == 0) { indexx.push_back(str[j] - 64); n++; }
			ABC[str[j] - 64] = 1;

			//ABC >> len:3  A는 3-0(천의 자리), B는 3-1=2(백의 자리), C는 3-2=1 (십의자리)
			d[len - j].push_back(str[j] - 64);
		}
	}

	P(0);

	printf("%d", maxx);
}
