#include <stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = n-i; j > 0; j--) {
			printf("*");
		}
		if (i != n-1) {
			printf("\n");
		}
		
	}
	return 0;
}