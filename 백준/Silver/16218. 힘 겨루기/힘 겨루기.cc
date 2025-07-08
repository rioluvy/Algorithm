#include<iostream>
#include<cmath>
using namespace std;

int main(){
  double n, k, a, b, human = 0, robot = 0;
  cin >> n >> k;
  bool flag = false;
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    human += a;
    robot += b;
    double op = human + floor(a*0.5);
    if(human - robot >= 50 || op - robot >= 50){
      cout << 1;
      flag = true;
      break;
    }
    if(human >= k && robot >= k){
      cout << 1;
      flag = true;
      break;
    }
    if(robot >= k){
      cout << -1;
      flag = true;
      break;
    }
    if(human >= k || op >= k){
      cout << 1;
      flag = true;
      break;
    }
  }
  if(!flag) cout << 0;
}