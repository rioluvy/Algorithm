#include<iostream>
#include<string>
using namespace std;

bool arr[26][26];

int main(){
  int n;
  string a, is, b;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a >> is >> b;
    arr[a[0] - 'a'][b[0] - 'a'] = true;
  }

  for(int i = 0; i < 26; i++){
    for(int j = 0; j < 26; j++){
      for(int k = 0; k < 26; k++){
        if(arr[j][i] && arr[i][k]) arr[j][k] = true;
      }
    }
  }

  int m;
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> a >> is >> b;
    if(arr[a[0] - 'a'][b[0] - 'a']) cout << "T\n";
    else cout << "F\n";
  }
}