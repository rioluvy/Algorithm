#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int n, t, k;
vector<int> diff(1002,0);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int a, b;
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> a >> b;
            diff[a]++;
            diff[b]--;
        }
    }

    vector<ll> cnt(1000,0);
    vector<ll> psum(1001,0);
    int cur = 0;
    for(int i = 0; i < 1000; i++){
        cur += diff[i];
        cnt[i] = cur;
    }
    for(int i = 0; i < 1000; i++) psum[i+1] = psum[i] + cnt[i];

    int m = 1000-t;
    int ans = 0;
    ll tmp = -1;
    for(int i = 0; i <= m; i++){
        if(psum[i+t]-psum[i] > tmp){
            tmp = psum[i+t]-psum[i];
            ans = i;
        }
    }
    cout << ans << " " << ans+t;

}