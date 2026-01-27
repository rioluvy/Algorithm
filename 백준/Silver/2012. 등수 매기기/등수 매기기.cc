#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;

int n, arr[500001];
ll ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr,arr+n);
    for(int i = 0; i < n; i++){
        ans += abs(arr[i]-(i+1));
    }
    cout << ans;
}