#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int main(){
    ll min,max,start,tmp;
    cin >> min >> max;
    int check[1000001] = {0,};
    for(ll i = 2; i < (int)sqrt(max)+1; i++){
        tmp = i*i;
        if(tmp <= max){
            start = (min/tmp)*tmp;
            for(ll j = start; j < max+1; j+=tmp){
                if(j>=min) check[j-min] = 1;
            }
        }
    }
    int ans=0;
    for(auto v : check){
        if(v) ans++;
    }
    cout << max-min+1-ans;
}