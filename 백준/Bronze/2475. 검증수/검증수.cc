#include <stdio.h>
#include <math.h>
int main() {
	int a, b, c, d, e;
	int i;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	i = pow(a, 2) + pow(b, 2) + pow(c, 2) + pow(d, 2) + pow(e, 2);
	i = i % 10;
	printf("%d", i);

}