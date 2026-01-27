#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;

int n, k, arr[20001], ans;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i]=='H') continue;
        int tmp = (i-k)<0 ? 0:i-k;
        bool flag = false;
        for(int j = tmp; j < i; j++){
            if(s[j] == 'H' && !arr[j]) {
                arr[j] = 1;
                flag = true;
                break;
            }
        }
        if(!flag){
            int tmp2 = (i+k)>n-1 ? n-1:i+k;
            for(int j = i+1; j <= tmp2; j++){
                if(s[j] == 'H' && !arr[j]){
                    arr[j] = 1;
                    break;
                }
            }
        }
        flag = true;
    }

    for(int i = 0; i < n; i++)
        if(arr[i]) ans++;

    cout << ans;
}