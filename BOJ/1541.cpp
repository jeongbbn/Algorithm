#include <iostream>
#include <cstring>
using namespace std;

char s[51],str[51];
int arr[51];
int main() {
	scanf("%s", s);
	for (int i = 0; s[i]; i++)	str[i]=s[i];

	char sep[3] = "+-"; 
	char *token;
	token = strtok(str, sep);
	int i = 0;
	while (token) {
		arr[i] = atoi(token);
		token = strtok(NULL, sep);
		i++;
	}

	int k = 0, sum=0;
	bool flag = 0;
	for (int i = 0; s[i] ; i++)
	{
		if (s[i] != '-' && s[i] != '+') continue;
		if (flag == 0){
			sum += arr[k];
			k++;

			if(s[i]=='-') flag = 1;
		}

		else {
			sum -= arr[k];
			k++;
		}

	}
	if (flag == 1) sum -= arr[k];
	else sum += arr[k];

	printf("%d", sum);

}
