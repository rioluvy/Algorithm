#include <stdio.h>
#pragma warning(disable: 4996)
int main(void) {
	int n, m=1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			printf(" ");
		}
		for (int j = 1; j <= 2 * n - m; j++) {
			printf("*");
		}
		
		printf("\n");
		m += 2;
	}
	return 0;
}