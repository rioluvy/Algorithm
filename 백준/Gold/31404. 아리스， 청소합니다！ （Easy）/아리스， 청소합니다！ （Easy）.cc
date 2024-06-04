#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;

bool dust[65][65];
bool cache[65][65][4];
int ruleA[65][65];
int ruleB[65][65];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int H,W,r,c,d;

int clearCache(){
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			for(int k = 0; k < 4; k++){
				cache[i][j][k] = false;
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	string s;
	cin >> H >> W >> r >> c >> d;


	for(int i = 0; i < H; i++){
		cin >> s;
		for(int j = 0; j < W; j++){
			ruleA[i][j] = s[j]-'0';
		}
	}
	for(int i = 0; i < H; i++){
		cin >> s;
		for(int j = 0; j < W; j++){
			ruleB[i][j] = s[j] - '0';
		}
	}

	int cnt = 0, ans = 0;
	while(true){
		if(r<0 || r>=H || c<0 || c>=W) break;
		if(cache[r][c][d]) break;

		if(dust[r][c]) {
			cache[r][c][d] = true;
			d = (d+ruleB[r][c])%4;
		}
		else {
			clearCache();
			dust[r][c] = true;
			d = (d+ruleA[r][c])%4;
			ans = cnt;
		}
		r += dx[d], c += dy[d];
		cnt++;
	}
	cout << ans+1;
}
