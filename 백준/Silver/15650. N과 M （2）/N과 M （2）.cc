#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> s;
void sequence(int n, int ,int tmp);
int main(void){
  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n; cin >> m;
  sequence(n,m,1);
  return 0;
}

void sequence(int n, int m, int tmp){
  if (s.size() == m){
    for(int i = 0; i < s.size(); i++) cout << s[i] << ' ';
    cout << endl;
    return;
  }
  for(int j = tmp; j < n+1; j++){
    if(find(s.begin(), s.end(),j) == s.end()){
      s.push_back(j);
      sequence(n, m, j+1);
      s.pop_back();
    }

  }

}