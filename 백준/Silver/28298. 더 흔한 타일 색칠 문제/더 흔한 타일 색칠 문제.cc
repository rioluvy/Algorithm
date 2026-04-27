#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl "\n"
using namespace std;

int main() {
	int n, m, k;
	string tmp;
	cin >> n >> m >> k;
	vector<vector<char>> arr(n);
	for(int i = 0; i < n; i++){
		cin >> tmp;
		for(int j = 0; j < m; j++){
			arr[i].push_back(tmp[j]);
		}
	}
	
	int ans = 0;
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			vector<int> cnt(26,0);
			for(int a = 0; a < n-k+1; a+=k){
				for(int b = 0; b < m-k+1; b+=k){
					char alpha = arr[a+i][b+j];
					cnt[alpha-65]++;
				}
			}
			int max_cnt = *max_element(cnt.begin(),cnt.end());
			int max_idx = max_element(cnt.begin(),cnt.end())-cnt.begin();
			char change = (char)(max_idx + 65);
			ans += ((n/k*m/k) - max_cnt);
			for(int a = 0; a < n-k+1; a+=k){
				for(int b = 0; b < m-k+1; b+=k){
					arr[a+i][b+j] = change;
				}
			}
		}
	}
	cout << ans << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << arr[i][j];
		}
		cout << endl;
	}
}