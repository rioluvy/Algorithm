#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define endl "\n"

using namespace std;
struct KEM{
  string name;
  int kor, eng, math;
};
bool compare(KEM x, KEM y);
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<KEM> num(n);
  for(int i = 0; i < n; i++){
    cin >> num[i].name >> num[i].kor >> num[i].eng >> num[i].math;
  }
  stable_sort(num.begin(), num.end(), compare);
  for(int i = 0; i < n; i++){
    cout << num[i].name << endl;
  }
}

bool compare(KEM x, KEM y){
  if(x.kor == y.kor && x.eng == y.eng && x.math == y.math) return x.name < y.name;
  else if(x.kor == y.kor && x.eng == y.eng) return x.math > y.math;
  else if(x.kor == y.kor) return x.eng < y.eng;
  return x.kor > y.kor;
}