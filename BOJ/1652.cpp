#include <iostream>
using namespace std;

int n, ans1, ans2;
char arr[105][105];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf(" %c", &arr[i][j]);
		}
	}
	
	//가로
	for(int i=0;i<n;i++){
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(arr[i][j]=='.') cnt++;
			else {
				if(cnt>=2) ans1++;
				cnt=0;
			}
		}
		if(cnt>=2) ans1++;
	}
	printf("%d ",ans1);
	//세로
	for(int i=0;i<n;i++){
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(arr[j][i]=='.') cnt++;
			else {
				if(cnt>=2) ans2++;
				cnt=0;
			}
		}
		if(cnt>=2) ans2++;
	}
	printf("%d",ans2);
	return 0;
}
