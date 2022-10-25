#include <stdio.h>
int main() {
	int h, m;
	int change;
	scanf("%d%d", &h, &m);
	if (m >= 45) m = m - 45;
	else {
		if (h == 0) {
			h = 23;
			m = 60 - (45 - m);
		}
		else {
			h = h - 1;
			m = 60 - (45 - m);
		}
	}
	printf("%d %d",h, m);
}