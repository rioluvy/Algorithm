#include <cstdio>
#include <algorithm>

using namespace std;

int n;
double arr[10][10];

int main(){
	scanf("%d", &n);
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			scanf("%lf", &arr[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		double pivot = arr[i][i];
		for(int j = i; j <= n; j++){
			arr[i][j] /= pivot;
		}
		for(int j = i+1; j <= n; j++){
			double tmp = arr[j][i];
			for(int k = i; k <= n; k++){
				arr[j][k] -= (arr[i][k] * tmp);
			}
		}
	}
	
	for(int i = n-1; i >= 0; i--){
		for(int j = i-1; j >= 0; j--){
			double tmp = arr[j][i];
			for(int k = i; k <= n; k++){
				arr[j][k] -= (arr[i][k] * tmp);
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		printf("%.0lf ", arr[i][n]);
	}
	
}