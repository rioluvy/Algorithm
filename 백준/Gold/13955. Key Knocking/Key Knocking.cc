#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, preset[8] = {1,2,0,1,1,0,2,1};
string s;
vector<int> ans;

int cal(const string& str){
  int cnt = 0;
  for(int i = 0; i < str.size()-1; i++){
    if(str[i] != str[i+1]) cnt++;
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  int len = s.length();
  n = len / 3;

  if(cal(s) >= 2*n){
    cout << 0;
    return 0;
  }

  for(char &c: s) c -= '0';

  int firstVal = s[0] * 4 + s[1] * 2 + s[2];
  if (preset[firstVal]) ans.push_back(preset[firstVal]);

  for(int i = 3; i < len; i += 3){
    if(cal(s.substr(i-1,4)) >= 2) continue;

    s[i] ^= 1; s[i+1] ^= 1;
    if(cal(s.substr(i-1,4)) >= 2){
      ans.push_back(i+1);
      continue;
    }
    s[i] ^= 1; s[i+1] ^= 1;

    s[i + 1] ^= 1; s[i + 2] ^= 1;
    if(cal(s.substr(i-1,4)) >= 2){
      ans.push_back(i+2);
    }
  }

  cout << ans.size() << "\n";
  for(int v : ans) cout << v << " ";
}