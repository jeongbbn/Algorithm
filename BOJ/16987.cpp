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

pi arr[10];
int N, maxx = -1;

bool visit[10];

int tmp[10];
void P(int h) {

	if (h >= N) { 
		int cnt = 0;
		for (int i = 0; i < N; i++)
			if (tmp[i] <= 0) cnt++;
		maxx = maxx > cnt ? maxx : cnt;
		return;
	}
	bool flag = 0;

	if (tmp[h] <= 0) P(h + 1); //h가 깨져있으면 다음꺼로 바꾼다.

	else {
		for (int i = 0; i < N; i++)
		{
			if (h == i) continue; //자기자신을 깨려고 하면, 다음꺼로 바꿔준다.
			if (tmp[i] <= 0) continue; // 이미 깨져있으면 다음 것을 깬다.

				/*visit[i] = 1; 깨지지 않았다면, 다시 칠 수 있다. visit이 필요없다.*/ 

				flag = 1; //아무것도 깨지않을 경우

				tmp[i] = tmp[i] - arr[h].second;
				tmp[h] = tmp[h] - arr[i].second;

				P(h + 1);

				tmp[i] = tmp[i] + arr[h].second;
				tmp[h] = tmp[h] + arr[i].second;
				//visit[i] = 0;
		}
	}
	if (!flag) P(h+1); //아무것도 안깼다 == 모두 깨져있다 == h+1을 계속 늘려서 끝내면 됨
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		arr[i].first = a;
		arr[i].second = b;
	}

	for (int i = 0; i < N; i++)
		tmp[i] = arr[i].first;

	P(0);

	printf("%d", maxx);
}
