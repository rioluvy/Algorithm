#include<iostream>
#include<cstring>
using namespace std;

int n, cache[10001];
double m, tmp;

struct candy{
  int cal, price;
};

int main(){
  while(cin >> n >> m){
    if(n == 0 && m == 0) break;
    memset(cache,0,sizeof(cache));
    int mm = (int)(m*100+0.5);
    candy arr[5001];
    for(int i = 1; i <= n; i++){
      cin >> arr[i].cal >> tmp;
      arr[i].price = (int)(tmp*100+0.5);
    }
    for(int i = 1; i <= n; i++){
      for(int j = arr[i].price; j <= mm; j++){
        cache[j] = max(cache[j],cache[j-arr[i].price]+arr[i].cal);
      }
    }
    cout << cache[mm] << "\n";
  }
}