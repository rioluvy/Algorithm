#include <iostream>
#include <iomanip>
using namespace std;

int n;
double p[20][20], dp[1<<20];

double trial(int cur, int visited){
  if(cur == n){
    return 1.0;
  }
  double &ret = dp[visited];
  if(ret != -1) return ret;
  ret = 0;
  for(int i = 0; i < n; i++){
    if(!(visited & (1<<i))){
      ret = max(ret, trial(cur+1, visited|(1<<i))*p[cur][i]);
    }
  }
  return ret;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> p[i][j];
      p[i][j] /= 100;
    }
  }
  for(int i = 0; i < (1<<20); i++){
    dp[i] = -1;
  }
  cout << fixed << setprecision(6) << trial(0,0)*100.0;
}