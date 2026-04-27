#include <iostream>
using namespace std;

struct p{
	int c, d;
};

int main() {
	p uni,dal,po;
	int hp;
	cin >> uni.c >> uni.d;
	cin >> dal.c >> dal.d;
	cin >> po.c >> po.d;
	cin >> hp;
	int ans = 0;
	while(true){
		if(ans == 0){
			hp -= (uni.d+dal.d+po.d);
		}
		else{
			if(ans % uni.c == 0) hp -= uni.d;
			if(ans % dal.c == 0) hp -= dal.d;
			if(ans % po.c == 0) hp -= po.d;
		}
		if(hp <= 0) break;
		ans++;
	}
	cout << ans;
}