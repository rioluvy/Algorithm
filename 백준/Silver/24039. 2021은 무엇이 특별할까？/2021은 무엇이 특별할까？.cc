#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPrime(int num){
  if(num < 2) return false;
  for(int i = 2; i <= sqrt(num); i++){
    if(num%i == 0) return false;
  }
  return true;
}

int main(){
  int n, prev = 2, cur = 3;
  cin >> n;
  while(true){
    int prod = prev*cur;
    if(prod > n){
      cout << prod;
      break;
    }
    int tmp = cur+1;
    while(!isPrime(tmp)) tmp++;
    prev = cur;
    cur = tmp;
  }
}