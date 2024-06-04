#include <iostream>
using namespace std;

int arr[100001];
bool arrr[100001];
bool check[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int n, m, a, b, s, tmp = 0, ans;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		if(check[a] || check[b]) tmp = 1;
		check[a] = true; check[b] = true;
		arr[a] = b;
		arrr[b] = true;
	}
	cin >> s;
	if(arr[s] != 0){
		cout << "NOJAM";
		return 0;
	} 
	else{
		if(!arrr[s]){
			ans = n-m-1;
		}
		else{
			ans = n-m;
			for(int i = 1; i < n+1; i++){
				if(i != s && ans == 2 && !arrr[i] && arr[i] == 0){
					ans--;
				}
			}
			
		}
		
	}
	if(ans > 1) cout << ans;
	else cout << "NOJAM";
	
}