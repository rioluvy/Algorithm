#include <iostream>
#define endl "\n"
using namespace std;
int main(){
    int t,n;
    cin >> t;
    int dp[2001] = {1,};
    for(int i = 1; i < 2001; i++){
        for(int j = 2000; j >= i ; j--){
            dp[j] = (dp[j] + dp[j-i])%100999;
        }
    }
    while(t--){
        cin >> n;
        cout << dp[n] << endl;
    }
}