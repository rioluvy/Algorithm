#include <iostream>
#define ll long long
#define endl "\n"
using namespace std;

ll n,b;
ll arr[5][5];
ll ans[5][5];
ll multi_arr[5][5];

int multi(ll a[5][5], ll b[5][5]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			multi_arr[i][j] = 0;
			for(int k = 0; k < n; k++){
				multi_arr[i][j] += (a[i][k]*b[k][j]);
			}
			multi_arr[i][j] %= 1000;
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = multi_arr[i][j];
		}
	}
	return 0;
}

int main() {
	cin >> n >> b;
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
		ans[i][i] = 1;
	}
	
	while(b>0){
		if(b%2==1) multi(ans,arr);
		multi(arr,arr);
		b/=2;
	}
	
	for(int i = 0 ; i< n; i++){
		for(int j = 0; j < n; j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
	
	
}