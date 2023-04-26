#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int p1(int n, int *arr);
int p2(int n, int *arr);
int main(void){
  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  int stock[14];
  for(int i = 0; i<14; i++){
    cin >> stock[i];
  }
  int person1 = p1(n, stock);
  int person2 = p2(n, stock);
  if(person1 > person2) cout << "BNP";
  else if(person1 < person2) cout << "TIMING";
  else cout << "SAMESAME";

}

int p1(int n, int *arr){
  int remain = n, cnt = 0;
  for(int i = 0; i<14; i++){
    if(remain >= arr[i]){
      cnt = remain / arr[i];
      remain = remain % arr[i];
    }
  }
  return remain + cnt * arr[13];
}

int p2(int n, int *arr){
  int day_check_up = 0, day_check_down = 0;
  int yesterday, remain = n, cnt = 0;
  for(int i = 1; i<14; i++){
    yesterday = arr[i-1];
    if (yesterday < arr[i]){
      day_check_up++;
      day_check_down = 0;
      if(day_check_up >= 3){
        remain += cnt * arr[i];
        cnt = 0;
      }
    }else if(yesterday > arr[i]){
      day_check_down--;
      day_check_up = 0;
      if (day_check_down <= -3){
        cnt += remain / arr[i];
        remain = remain % arr[i];
      }
    }else{
      day_check_down = 0;
      day_check_up = 0;
    }
  }
  return remain + cnt * arr[13];
}