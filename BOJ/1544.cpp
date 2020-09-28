#include <iostream>
#include <vector>
using namespace std;

char str[55][55];
int n, len[55], cnt;

void issame(char str1[], int str1len, char str2[], int str2len) {
	if (str1len != str2len) return;
	
	int length = str1len;
	vector<int>start;
	
	for (int i = 0; i < length; i++)
		if (str1[0] == str2[i]) start.push_back(i); 
													
	bool flag = false; 
	for (int i = 0; i < start.size(); i++) 
	{
		flag = true;
		int  k = start[i];
		for (int j = 0; j < length; j++, k++) 
		{
			if (k == length) k = 0;
			if (str1[j] != str2[k]) { flag = false; break; } 
		}
		if (flag == true) {
			str2[0] = '.';
			return;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
		
		int lencnt = 0;
		for (int j = 0; str[i][j]; j++) ++lencnt;
		len[i] = lencnt;
	}

	for (int i = 0; i < n; i++) 
	{
		if (str[i][0] == '.') continue;
		for (int j = i+1; j < n; j++)
		{
			if (str[j][0] == '.') continue;
			issame(str[i], len[i], str[j], len[j]);
		}
	}

	for (int i = 0; i < n; i++) 
	{
		if (str[i][0] == '.') continue;
		cnt++;
	}
	printf("%d", cnt);

}
