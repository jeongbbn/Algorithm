#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char str[1000001];
	char *sep = " ";
	char *token;
	int cnt = 0;

	if (0 == scanf("%[^\n]s", str)) cnt = -1;
	token = strtok(str,sep);

	while (token) {
		cnt++;
		token = strtok(NULL, sep);
	}
	printf("%d", cnt);
}
