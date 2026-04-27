#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t,n,m;
    cin >> t;
    ll dp[10001] = {0,};
    int coin[21];
    while(t--){
        cin >> n;
        for(int i = 1; i < n+1; i++){
            cin >> coin[i];
        }
        cin >> m;

        dp[0] = 1;
        for(int i = 1; i < n+1; i++){
            for(int j = coin[i]; j < m+1; j++){
                dp[j] = dp[j]+dp[j-coin[i]];
            }
        }
        cout << dp[m] << endl;
        memset(dp,0,sizeof(dp));
    }
}