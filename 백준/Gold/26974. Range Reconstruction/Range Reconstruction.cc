#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[301][301], ans[301], a, b, tmp, ab;
int n;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			cin >> arr[i][j-i];
		}
	}
	for(int i = n-2; i >= 0; i--){
		ans[i] = ans[i+1] + arr[i][1];
		for(int j = 2; j < n-i; j++){
			tmp = arr[i][j];
			a = *max_element(ans+i,ans+i+j+1);
			b = *min_element(ans+i,ans+i+j+1);
			ab = a - b;
			if(ab != tmp){
				ans[i] = ans[i+1] - arr[i][1];
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
}