#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,m,s,e,ans;
    int arr[2001];
    cin >> n;
    for(int i=1;i<n+1;i++){
      cin >> arr[i];
    }
    int check[2001][2001]={0,};
    for(int i=1;i<n+1;i++){
      check[i][i] = 1;
      if(i!=n && arr[i]==arr[i+1]){
        check[i][i+1]=1;
      }
    }

    for(int i=n-2;i>0;i--){
      for(int j=n;j>i;j--){
        if(arr[i]==arr[j] && check[i+1][j-1]) check[i][j]=1;
      }
    }
    cin >> m;
    while(m--){
      ans = 0;
      cin >> s >> e;
      if(check[s][e]) ans = 1;
      cout << ans << endl;
    }
}