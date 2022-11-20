#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#pragma warning(disable: 4996)
int main() {
	int n, m, b, saveb, newtime;
	scanf("%d%d%d", &n, &m, &b);
	saveb = b;
	int** land;
	land = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		land[i] = (int*)malloc(sizeof(int) * m);
	}
	int highest = 0, lowest = 256;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &land[i][j]);
			if (land[i][j] < lowest) lowest = land[i][j];
			else if (land[i][j] > highest) highest = land[i][j];
		}
	}
	int height = lowest;
	int time = INT_MAX;
	for (int h = lowest; h < highest + 1; h++) {
		int work1 = 0, work2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (land[i][j] > h) {
					work1 += land[i][j] - h;
					b += land[i][j] - h;
				}
				else if (land[i][j] < h) {
					work2 += h - land[i][j];
					b -= h - land[i][j];
				}
			}
		}
		if (b < 0) {
			b = saveb;
			continue;
		}
		else {
			newtime = work1 * 2 + work2;
			if (newtime <= time) {
				time = newtime;
				if (height < h) {
					height = h;
				}
			}b = saveb;
		}
	}printf("%d %d\n", time, height);
	for (int i = 0; i < n; i++) {
		free(land[i]);
	}
	free(land);

	return 0;
}