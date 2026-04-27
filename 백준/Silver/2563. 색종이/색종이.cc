#include <iostream>

using namespace std;
int n,x,y,cnt;
int arr[101][101];
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		for(int j = x; j < x+10; j++){
			for(int k = y; k < y+10; k++){
				if(!arr[j][k]){
					arr[j][k] = 1;
					cnt++;
				}
			}
		}
	}
	cout << cnt;
}