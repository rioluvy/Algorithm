#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//int dp[200001][7];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        //memset(dp,0,sizeof(dp));
        int n, v1,v2;
        char op1,op2;
        cin >> n;
        vector<vector<int>> dp(n+1,vector<int>(7));
        dp[0][1] = 1;
        for(int i = 1; i < n+1; i++){
            cin >> op1 >> v1 >> op2 >> v2;
            for(int j = 0; j < 7; j++){
                if(!dp[i-1][j]) continue;
                if(op1 == '+') dp[i][(j+v1)%7] = 1;
                else dp[i][(j*v1)%7] = 1;
                if(op2 == '+') dp[i][(j+v2)%7] = 1;
                else dp[i][(j*v2)%7] = 1;
            }
        }
        cout << (dp[n][0] ? "LUCKY\n" : "UNLUCKY\n");
    }
}