#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	int n, tmp, cnt=0;
	cin >> n;
	cout << n << "\n";
	if(n%3==2){
		cout << 1 << " " << 2 << " " << 4 << " ";
		tmp = 3;
		for(int i = 0; i < n-3; i++){
			cout << tmp << " ";
			if(cnt<2) {
				cnt++;
				tmp+=2;
			}else{
				cnt=0;
				tmp--;
			}
		}
	}else{
		cout << 1 << " " << 3 << " ";
		tmp = 2;
		for(int i = 0; i < n-2; i++){
			cout << tmp << " ";
			if(cnt<2){
				cnt++;
				tmp+=2;
			}else{
				cnt=0;
				tmp--;
			}
		}
	}
	cout << 1;
}