#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

vector<vector<char>> arr;
string s;

void decompress(string::iterator& it, int x, int y, int size){
  char head = *(it++);
  if(head == 'W' || head == 'B'){
    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        arr[x+i][y+j] = head;
      }
    }
  }
  else{
    int half = size/2;
    decompress(it, x, y, half);
    decompress(it,x, y+half, half);
    decompress(it,x+half,y,half);
    decompress(it,x+half, y+half, half);
  }
}

int main(){
  int n; cin >> n;
  arr.assign(n,vector<char>(n,'\0'));
  cin >> s;
  auto it = s.begin();
  decompress(it,0,0,n);

  cout << "#define quadtree_width " << n << "\n";
  cout << "#define quadtree_height " << n << "\n";
  cout << "static char quadtree_bits[] = {\n";

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j+=8){
      int tmp = 0;
      for(int k = 0; k < 8; k++){
        if(arr[i][j+k] == 'B'){
          tmp |= (1<<k);
        }
      }
      cout << "0x" << hex << setw(2) << setfill('0') << tmp << ',';
    }
    cout << "\n";
  }
  cout << "};";
}