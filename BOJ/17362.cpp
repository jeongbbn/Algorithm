#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int x = n%8;
	if(x==1) printf("1");
	else if(x==2 || x==0) printf("2");
	else if(x==3||x==7) printf("3");
	else if(x==4 || x==6) printf("4");
	else printf("5");
	return 0;
}
