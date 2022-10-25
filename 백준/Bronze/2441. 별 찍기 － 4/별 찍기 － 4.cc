#include <stdio.h>
#pragma warning(disable: 4996)
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			printf(" ");
		}
		for (int j = n; j > i; j--) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}