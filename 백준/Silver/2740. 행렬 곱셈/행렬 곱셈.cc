#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int matrixA[101][101];
int matrixB[101][101];
int main() {
	int n, m, k;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> matrixA[i][j];
		}
	}
	cin >> m >> k;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < k; j++){
			cin >> matrixB[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			int tmp = 0;
			for(int x = 0; x < m; x++){
				tmp += matrixA[i][x] * matrixB[x][j];
			}
			cout << tmp << " ";
		}
		cout << endl;
	}
}