#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int letters[26], weighted[26], visited[10], leaders[26];

int trial(int idx, int total){
  if(idx == 26){
    return (total == 0) ? 1 : 0;
  }
  if(!letters[idx]) return trial(idx+1, total);

  int ret = 0;
  for(int i = 0; i < 10; i++){
    if(!visited[i]){
      if(leaders[idx] == 1 && i == 0) continue;
      visited[i] = 1;
      ret += trial(idx+1, total + weighted[idx]*i);
      visited[i] = 0;
    }
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while(cin >> n && n != 0){
    memset(letters,0,sizeof(letters));
    memset(leaders,0,sizeof(leaders));
    memset(weighted,0,sizeof(weighted));
    memset(visited,0,sizeof(visited));
    string s;
    for(int i = 0; i < n; i++){
      cin >> s;
      if(s.length() > 1){
        leaders[s[0] - 'A'] = 1;
      }
      int weight = (i == n-1) ? -1 : 1;
      for(int j = s.length()-1; j >= 0; j--){
        weighted[s[j] - 'A'] += weight;
        letters[s[j] - 'A'] = 1;
        weight *= 10;
      }
    }
    cout << trial(0,0) << "\n";
  }
}