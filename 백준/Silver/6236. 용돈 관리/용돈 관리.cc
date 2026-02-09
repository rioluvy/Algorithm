#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, arr[100001];
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int l,h,mid;
    l = *max_element(arr,arr+n); h = 1000000000;
    int ans = h;
    while(l <= h){
        mid = (l+h)/2;
        int cnt = 0;
        int left = 0;
        for(int i = 0; i < n; i++){
            if(left < arr[i]){
                cnt++;
                left = mid;
            }
            left -= arr[i];
        }
        if(cnt <= m) {
            ans = mid;
            h = mid-1;
        }
        else if(cnt > m) l = mid+1;
    }
    cout << ans;
}