#include <iostream>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int weight[102];
    int value[102];
    int *dp = new int[k+2];
    for(int i = 1; i < n+1; i++){
        cin >> weight[i] >> value[i];
    }

    for(int i = 1 ; i < n+1; i++){
        for(int j = k; j >= weight[i]; j--){
            dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    cout << dp[k];
}