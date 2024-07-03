#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

int n,m,k,nx,ny,ans;
int map[1001][1001];
int visited[1001][1001][11];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(1,1,0));
    bool flag = false;
    while(!q.empty()){
        auto [x,y,cnt] = q.front();
        q.pop();
        if(x == n && y == m){
            flag = true;
            ans = visited[x][y][cnt]+1;
            break;
        }
        for(int i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
            if(visited[nx][ny][cnt]) continue;
            if(!map[nx][ny]){
                visited[nx][ny][cnt] = visited[x][y][cnt] + 1;
                q.push(make_tuple(nx,ny,cnt));
            }
            else{
                if(cnt == k) continue;
                if(visited[nx][ny][cnt+1] != 0) continue;
                visited[nx][ny][cnt+1] = visited[x][y][cnt] + 1;
                q.push(make_tuple(nx,ny,cnt+1));
            }
        }
    }
    if(flag) printf("%d", ans);
    else printf("%d", -1);
}