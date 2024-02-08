#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;

bool dust[65][65];
int cache[65][65][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int H,W,r,c,d;
	string s;
	cin >> H >> W >> r >> c >> d;
	int ruleA[65][65];
	int ruleB[65][65];

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

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int save_cnt = 0, cnt = 0;
	while(r >= 0 && r < H && c >= 0 && c < W){
        if(!dust[r][c]){
            dust[r][c] = true;
            d = (d+ruleA[r][c])%4;
            save_cnt = cnt;
        }else{
            if(cache[r][c][d] == 4096){
                break;
            }
            cache[r][c][d]++;
            d = (d+ruleB[r][c])%4;
        }
        r = r+dx[d];
        c = c+dy[d];
        cnt++;
    }
    cout << save_cnt+1;
}
