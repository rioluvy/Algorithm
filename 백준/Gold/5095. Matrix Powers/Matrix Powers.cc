#include <iostream>
#include <cstring>
#define endl "\n"
#define lint long long
using namespace std;

int n,m,p;

struct tmp {
	lint arr[101][101];
};

tmp operator*(tmp a, tmp b){
	tmp c;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			c.arr[i][j] = 0;
			for(int k = 0; k < n; k++){
				c.arr[i][j] += (a.arr[i][k] * b.arr[k][j]);
				c.arr[i][j] %= m;
			}
		}
	}
	return c;
}

int main() {
	while(true){
		tmp matrix, ans;
		memset(ans.arr,0,sizeof(ans.arr));
		cin >> n >> m >> p;
		if(!n && !m && !p) break;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix.arr[i][j];
			}
			ans.arr[i][i] = 1;
		}
		
		while(p){
			if(p&1) ans = ans * matrix;
			matrix = matrix * matrix;
			p >>= 1;
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << ans.arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}