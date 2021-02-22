#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n,ans;
	scanf("%d", &n);
	ans = n;
	for (int i = 0; i < n; i++) {
		int len,checker[26] = { 0 };
		char str[101];
		scanf("%s", str);
		len = strlen(str);
		checker[str[0] - 97] = 1;
		for (int j = 1; j < len; j++) {
			if (str[j-1] == str[j]) {
				checker[str[j] - 97] = 1;
			}
			else checker[str[j] - 97]++;

			if (checker[str[j] - 97] > 1) {
				ans--;
				break;
			}
		}
		memset(checker, 0, sizeof(checker));
	}
	printf("%d", ans);
}
