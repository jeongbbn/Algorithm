#include<iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
	string a,b;
	while (getline(cin, a) && !cin.eof())
		b += a;
	char *temp, *token;
	int sum = 0, len = b.size();
	temp = (char*)malloc(sizeof(char) * len);
	strcpy(temp, b.c_str());
	token = strtok(temp, ",");
	while (token) {
		sum += atoi(token);
		token = strtok(NULL, ",");
	}
	printf("%d", sum);
	return 0;
}
