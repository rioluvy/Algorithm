#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, soul[70001], arr[70001];
	cin >> n;
	for(int i = 1; i <= n; i++){
		soul[i] = n-i+1;
		cin >> arr[i];
	}
	
	if(arr[n] < 0){
		cout << -1;
		return 0;
	}
	
	int idx = 1, start, end;
	bool flag = false;
	vector<int> m;
	while(idx <= n){
		if(arr[idx] < 0){
			if(!flag){
				start = idx;
				flag = true;
			}
			idx++;
			continue;
		}
		if(!flag){
			idx++;
			continue;
		}
		end = idx;
		reverse(soul+start,soul+end+1);
		flag = false;
		idx++;
	}
	
	for(int i = 1; i <= n; i++) cout << soul[i] << " ";
}