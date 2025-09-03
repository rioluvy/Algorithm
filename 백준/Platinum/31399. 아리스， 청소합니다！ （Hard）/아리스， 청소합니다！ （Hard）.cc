#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<tuple>
#define lint long long
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

inline int stateId(int x, int y, int d, int col){
  return (x*col + y)*4+d;
}

inline tuple<int,int,int> statePos(int id, int row, int col){
  int d = id%4;
  id /= 4;
  int y = id%col;
  id /= col;
  int x = id;
  return {x,y,d};
}

struct DSU{
  vector<int> parent;
  vector<lint> w;

  DSU(int n = 0) {init(n);}
  void init(int n){
    parent.resize(n);
    w.assign(n,0);
    iota(parent.begin(),parent.end(),0);
  }

  int find(int x){
    if(x == parent[x]) return x;
    int p = parent[x];
    int r = find(p);
    w[x] += w[p]; // x -> p, p -> r
    parent[x] = r;
    return r;
  }

  void link(int x, int y){
    parent[x] = y;
    w[x] = 1;
  }
};

int main(){
  int row,col;
  cin >> row >> col;
  int x,y,d;
  cin >> x >> y >> d;
  vector<string> a(row);
  vector<string> b(row);
  for(auto& v : a) cin >> v;
  for(auto& v : b) cin >> v;
  vector<vector<char>> cleaned(row,vector<char>(col,0));
  const int T = row*col*4;
  DSU uf(T);

  auto inside = [&](int x, int y){
    return (0 <= x && x < row && 0 <= y && y < col);
  };

  auto nextState = [&](int x, int y, int d) -> tuple<int,int,int>{
    int rot = (cleaned[x][y] ? b[x][y] : a[x][y]) - '0';
    int nd = (d+rot)%4;
    int nx = x+dx[nd];
    int ny = y+dy[nd];
    return {nx,ny,nd};
  };

  auto jumpOver = [&](int x, int y, int d) -> tuple<int,int,int,lint>{
    lint dist = 0;
    while(true){
      int cur = stateId(x,y,d,col);
      int tmp = uf.find(cur);
      dist += uf.w[cur];

      auto [tmpx,tmpy,tmpd] = statePos(tmp,row,col);
      auto [nx,ny,nd] = nextState(tmpx,tmpy,tmpd);
      if(!inside(nx,ny)) return make_tuple(-1,-1,-1,-1);
      if(!cleaned[nx][ny]) return make_tuple(nx,ny,nd,dist+1);

      int nxt = stateId(nx,ny,nd,col);
      int nxtP = uf.find(nxt);
      if(nxtP == uf.find(tmp)) return make_tuple(-1,-1,-1,-1);
      uf.link(tmp,nxt);
      x = nx; y = ny; d = nd;
      dist++; 
    }
  };

  lint ans = 0;
  while(inside(x,y)){
    if(cleaned[x][y]){
      auto [nx,ny,nd,dist] = jumpOver(x,y,d);
      if(nx < 0) break;
      ans += dist;
      x = nx; y = ny; d = nd;
    }
    auto [nx,ny,nd] = nextState(x,y,d);
    cleaned[x][y] = 1;
    ans++;
    x = nx; y = ny; d = nd;
  }
  cout << ans;
}