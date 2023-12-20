#include <iostream>
#include <cstring>
using namespace std;

int cache[1001][1001];
int bino(int n, int k){
    if(k==0 || n == k) return cache[n][k] = 1;
    int &ret = cache[n][k];
    if(ret != -1) return ret;
    return cache[n][k] = (bino(n-1,k) + bino(n-1,k-1))%10007;
}
int main(){
    int n,k,ans;
    cin >> n >> k;
    memset(cache,-1,sizeof(cache));
    bino(n,k);
    cout << cache[n][k];
}