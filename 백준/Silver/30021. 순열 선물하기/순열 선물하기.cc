#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  if(n==1) cout << "YES\n1";
  else if(n==2) cout << "NO\n";
  else{
    cout << "YES\n1 3 2";
    for(int i = 4; i <= n; i++) cout << " " << i;
  }
}