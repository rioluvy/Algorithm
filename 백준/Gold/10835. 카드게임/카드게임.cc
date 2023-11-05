#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[2001][2001];
int leftCard[2001];
int rightCard[2001];
int solve(int left, int right){
    if(left >= n || right >= n) return 0;
    if(dp[left][right] != -1) return dp[left][right];
    dp[left][right] = 0;
    dp[left][right] = max(solve(left+1,right+1), solve(left+1,right));
    if(leftCard[left] > rightCard[right]){
        dp[left][right] = max(dp[left][right], solve(left,right+1)+rightCard[right]);
    }

    return dp[left][right];
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    fill(&dp[0][0],&dp[2000][2001],-1);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> leftCard[i];
    }
    for(int i = 0; i < n; i++){
        cin >> rightCard[i];
    }
    cout << solve(0,0);
}