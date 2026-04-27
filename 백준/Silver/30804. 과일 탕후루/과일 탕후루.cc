#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> fruits(n+1,0);
	for(int i = 1; i < n+1; i++){
		cin >> fruits[i];
	}
	
	vector<int> count(10,0);
	int left = 1, right = 1;
	int cnt = 0, ans = 0, length = 0;
	
	while(true){
		if(right == n+1) break;
		
		if(cnt <= 2){
			count[fruits[right]]++;
			right++;
		}else{
			count[fruits[left]]--;
			left++;
		}
		
		cnt = 0;
		length = 0;
		for(auto v : count){
			if(v!=0) {
				cnt++;
				length += v;
			}
		}
		if(cnt <= 2){
			ans = max(ans,length);
		}
	}
	cout << ans;
}