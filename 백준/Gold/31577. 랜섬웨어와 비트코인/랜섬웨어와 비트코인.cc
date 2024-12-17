#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main() {
    vector<int> bit;
    int arr[8];
    for(int i = 0; i < 120; i++){
        arr[i%8] = i%20+1;
        if((i+1)%8 == 0){
            sort(arr,arr+8);
            for(int j = 0; j < 8; j++){
                cout << arr[j] << " ";
            }
            cout << endl;
        }
    }
}