#include <iostream>
#include <cstring>
#define long long ll
using namespace std;

int cache[1001][1001];
int bino(int n, int k){
    if(k==0 || n == k) return cache[n][k] = 1;
    if(cache[n][k] != -1) return cache[n][k];
    return cache[n][k] = (bino(n-1,k) + bino(n-1,k-1))%10007;
}
int main(){
    int n,k,ans;
    cin >> n >> k;
    memset(cache,-1,sizeof(cache));
    bino(n,k);
    cout << cache[n][k];
}