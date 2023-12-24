#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int n,num;
    cin >> n;
    vector<int> card(n+1,0);
    for(int i = 0; i < n; i++){
        cin >> num;
        card[num]++;
    }
    long long ans = 1;
    for(int i = 1; i < n+1; i++){
        if(card[i] == 0) continue;
        ans *= (card[i]+1);
        ans %= MOD;
    }
    cout << ans - 1;
}