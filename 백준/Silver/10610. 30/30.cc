#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
  string s;
  int num = 0, flag = 0, flag2 = 0;
  cin >> s;
  for(int i = 0; i < s.length(); i++){
    if(s[i] == '0') flag = 1;
    num += (s[i] - '0');
  }
  if(num%3 == 0) flag2 = 1;
  if(!flag) {
    cout << -1;
    return 0;
  }
  if(flag2){
    sort(s.rbegin(),s.rend());
    cout << s;
  }else cout << -1;
}