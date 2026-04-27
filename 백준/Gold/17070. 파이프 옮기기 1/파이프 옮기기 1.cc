#include <iostream>
#include <queue>
#define piii pair<int,pair<int,int>>
using namespace std;

int house[20][20];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i < n+1; i++){
		for(int j = 1; j < n+1; j++){
			cin >> house[i][j];
			if(house[i][j]) house[i][j] = -1;
		}
	}
	if(house[n][n] == -1){
		cout << 0;
		return 0;
	}
	queue<pair<int,pair<int,int>>> q;
	q.push({0,{1,2}});
	house[1][2] = 1;
	while(!q.empty()){
		piii tmp = q.front();
		q.pop();
		int state = tmp.first;
		int x = tmp.second.first;
		int y = tmp.second.second;
		if(state == 0){
			if(y+1 <= n && house[x][y+1] != -1) {
				house[x][y+1]++;
				q.push({0,{x,y+1}});
			}
			if(x+1 <=n && y+1 <= n && house[x+1][y+1] != -1 && house[x][y+1] != -1 && house[x+1][y] != -1) {
				house[x+1][y+1]++;
				q.push({1,{x+1,y+1}});
			}
		}
		if(state == 1){
			if(y+1 <= n && house[x][y+1] != -1){
				house[x][y+1]++;
				q.push({0,{x,y+1}});
			}
			if(x+1 <= n && y+1 <= n && house[x+1][y+1] != -1 && house[x][y+1] != -1 && house[x+1][y] != -1){
				house[x+1][y+1]++;
				q.push({1,{x+1,y+1}});
			}
			if(x+1 <= n && house[x+1][y] != -1){
				house[x+1][y]++;
				q.push({2,{x+1,y}});
			}
		}
		if(state == 2){
			if(x+1<=n && house[x+1][y] != -1){
				house[x+1][y]++;
				q.push({2,{x+1,y}});
			}
			if(x+1<=n && y+1<=n && house[x+1][y+1] != -1 && house[x][y+1] != -1 && house[x+1][y] != -1){
				house[x+1][y+1]++;
				q.push({1,{x+1,y+1}});
			}
		}
	}
	cout << house[n][n];
}