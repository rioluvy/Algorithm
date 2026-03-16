#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
    FAST_IO
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> psum(n);
    for(auto &i:arr) cin >> i;

    psum[0] = arr[0];
    for(int i = 1; i < n; i++)
        psum[i] = psum[i-1] + arr[i];
    
    int ans = 0;
    for(int i = 1; i < n-1; i++){
        ans = max(ans, psum[n-1]*2-arr[0]-arr[i]-psum[i]);
        ans = max(ans,psum[i]-arr[0]+psum[n-1]-psum[i-1]-arr[n-1]);
        ans = max(ans, psum[n-1]-arr[n-1]-arr[i]+psum[i-1]);
    }

    cout << ans << "\n";
}