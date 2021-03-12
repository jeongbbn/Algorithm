#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int len;
void struprr(char *s) {
	for (int i = 0; i < len; i++) {
		if (s[i] >= 97) s[i] = s[i] - 32;
	}
}

int main() {
	char str[1000001], maxchar;
	int max = 0,arr[26] = { 0 };
	scanf("%s", str);
	len = strlen(str);
	struprr(str);
	maxchar = str[0];

	for (int i = 0; i < len; i++) {
		arr[str[i]-65]++;
		if (max > arr[str[i] - 65]) {
			max = max;
		}

		else if (max < arr[str[i] - 65]) {
			max = arr[str[i] - 65]; 
			maxchar = str[i];
		}

		else maxchar = '?';
	}
	printf("%c", maxchar);
}
