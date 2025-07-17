#include<iostream>
using namespace std;

int n, card[1000002];
bool flag;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> card[i];
  }

  for(int i = 1; i <= n; i++){
    if(!card[i]){
      for(int j = 1; j <= 3; j++){
        if(card[i-1] != j && card[i+1] != j){
          card[i] = j;
          break;
        } 
      }
    }
    if(card[i] == card[i+1]) flag = true;
  }
  if(flag) cout << -1;
  else{
    for(int i = 1; i <= n; i++) cout << card[i] << " ";
  }
}