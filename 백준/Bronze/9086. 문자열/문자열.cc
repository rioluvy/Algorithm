#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int main(){
  int t;
  string s;
  cin >> t;
  for(int i = 0; i < t; i++){
    cin >> s;
    cout << s[0] << s.at(s.size() -1) << endl;
  }
}