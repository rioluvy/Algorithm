#include<iostream>
#include<string>
using namespace std;

void isGood(string& s, int step, int n){
  if(step == n) {
    cout << s;
    exit(0);
  }
  for(int i = 1; i <= 3; i++){
    s += to_string(i);
    bool flag = true;
    for(int j = 1; j <= s.size()/2; j++){
      if(s.substr(s.size()-2*j,j) == s.substr(s.size()-j,j)) {
        flag = false;
        break;
      }
    }
    if(flag) {
      isGood(s,step+1,n);
    }
    s.pop_back();
  }
  return;
}

int main(){
  int n;
  string s = "";
  cin >> n;
  isGood(s,0,n);
}