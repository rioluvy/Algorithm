#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl "\n"
using namespace std;

struct Brick {
    int a, h, w, num;
};

bool compare(Brick x, Brick y){
    return x.a < y.a;
}

int main() {
    int n;
    cin >> n;
    vector<Brick> brick;
    Brick start = {0,0,0,0};
    brick.push_back(start);
    for(int i = 1; i <= n; i++){
        Brick b;
        cin >> b.a >> b.h >> b.w;
        b.num = i;
        brick.push_back(b);
    }
    sort(brick.begin(),brick.end(),compare);

    int dp[101], height = 0;
    memset(dp,0,sizeof(dp));
    
    //i번째 블록을 무조건 사용했을때 가능한 가장 높은 탑
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            if(brick[i].w > brick[j].w){
                dp[i] = max(dp[i],dp[j]+brick[i].h);
            }
        }
        height = max(height,dp[i]);
    }
    vector<int> ans;
    for(int i = n; i > 0 ; i--){
        if(dp[i] == height){
            ans.push_back(brick[i].num);
            height -= brick[i].h;
        }
    }
    cout << ans.size() << endl;
    reverse(ans.begin(),ans.end());
    for(auto v : ans) cout << v << endl;
}