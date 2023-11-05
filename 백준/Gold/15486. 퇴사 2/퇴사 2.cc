#include <iostream>
using namespace std;
int main(){
    int n;
    int time[1500002];
    int price[1500002];
    int dp[1500002] = {0,};
    cin >> n;
    for(int i = 1; i < n+1; i++){
        cin >> time[i] >> price[i];
    }
    for(int i = n; i > 0; i--){
        if(time[i] + i > n+1){
            dp[i]=dp[i+1];
            continue;
           }
        dp[i] = max(dp[i+1],dp[time[i]+i]+price[i]);
    }
    cout << dp[1];
}