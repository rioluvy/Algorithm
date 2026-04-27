#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
#define endl "\n"
using namespace std;

vector<string> ans;
int arr[20001] = {0,};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    queue<pair<int, string>> q;
    q.push({1, "1"});
    while (!q.empty()) {
      int num = q.front().first;
      string s = q.front().second;
      q.pop();
			num %= n;
			if(s.size()>100) break;
			if(!num){
				ans.push_back(s);
				break;
			}
      int case_1 = (num * 10) % n;
      int case_2 = (num * 10 + 1) % n;
			if(!arr[case_1]){
				arr[case_1] = 1;
				q.push({case_1, s + "0"});
			}
			if(!arr[case_2]){
				arr[case_2] = 1;
				q.push({case_2, s + "1"});
			}
    }
		if(ans.size()==0) cout << "BRAK" <<endl;
		else cout << ans[0] <<endl;
		memset(arr,0,sizeof(arr));
		ans.clear();
  }
}