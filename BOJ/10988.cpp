#include <iostream>
#include <string>
using namespace std;

string str;
int ans = 1;
int main() {
	cin >> str;
	int len = (int)str.length() - 1;
	for(int i=0;i<=len/2;i++){
		if(str[i] != str[len-i]) ans=0;
	}
	printf("%d",ans);
	return 0;
}
