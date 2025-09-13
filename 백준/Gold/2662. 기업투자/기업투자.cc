#include<iostream>
using namespace std;

int n, m, tmp, corp[21][301];
int cache[21][301], amount[21][301];

int main(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> tmp;
    for(int j = 1; j <= m; j++){
      cin >> corp[j][i];
    }
  }

  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      int &pMax = cache[i][j];
      for(int k = 0; k <= j; k++){
        //pMax = max(pMax, cache[i-1][j-k]+corp[i][k]);
        int tmp2 = cache[i-1][j-k]+corp[i][k];
        if(tmp2 > pMax){
          pMax = tmp2;
          amount[i][j] = k;
        }
      }
    }
  }
  cout << cache[m][n] << "\n";
  int invest[21], total = n;
  for(int i = m; i > 0; i--){
    invest[i] = amount[i][total];
    total -= amount[i][total];
  }
  for(int i = 1; i <= m; i++) cout << invest[i] << " ";
}