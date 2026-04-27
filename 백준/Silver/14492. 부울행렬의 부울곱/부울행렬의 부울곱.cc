#include <iostream>
using namespace std;

int main() {
	int a[301][301];
	int b[301][301];
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> b[i][j];
		}
	}
	int c[301][301];
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			c[i][j] = (a[i][0]&b[0][j]);
			for(int k = 1; k < n; k++){
				c[i][j] = c[i][j]|(a[i][k]&b[k][j]);
			}
			if(c[i][j]) cnt++;
		}
	}
	cout << cnt;
}