#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define ll long long
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    ll room[200001];
    ll n, s;
    cin >> n >> s;
    for(int i = 1; i < n+1; i++){
        cin >> room[i];
    }

    int left = s-1, right = s+1;
    ll ans = 0;
    ll left_sum = 0, right_sum = 0;
    ll left_max = 0, right_max = 0;
    bool check = true;
    while(check){
        check = false;
        while(left > 0 && left_sum + room[left] >= 0){
            left_sum += room[left];
            left--;
            if(ans < left_sum) break;
        }
        if(left_sum > ans){
            right_sum += (left_sum - ans);
            ans = left_sum;
            check = true;
        }
        
        while(right < n+1 && right_sum + room[right] >= 0){
            right_sum += room[right];
            right++;
            if(ans < right_sum) break;
        }
        if(right_sum > ans){
            left_sum += (right_sum-ans);
            ans = right_sum;
            check = true;
        }
    }
    cout << ans;
}