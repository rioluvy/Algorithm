#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	char arr[5] = {'U','C','P','C'};
	int pointer = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == arr[pointer]){
			pointer++;
		}
		if(pointer == 4) break;
	}
	if(pointer == 4) cout << "I love UCPC";
	else cout << "I hate UCPC";
}