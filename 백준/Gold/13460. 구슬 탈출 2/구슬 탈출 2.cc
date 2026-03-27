#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
using namespace std;

char arr[11][11];
int n, m, visited[11][11][11][11];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

struct Ball{
    int rx, ry, bx, by, cnt;
};

pii trial(int x, int y, int d){
    while(true){
        int nx = x+dx[d];
        int ny = y+dy[d];
        if(arr[nx][ny] == 'O') {
            x = nx; y = ny;
            break;
        }
        if(arr[nx][ny] == '#') break;
        x = nx; y = ny;
    }
    return {x,y};
}

int main(){
    FAST_IO
    cin >> n >> m;
    int holeX, holeY, rx, ry, bx, by;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'R') rx = i, ry = j, arr[i][j] = '.';
            else if(arr[i][j] == 'B') bx = i, by = j, arr[i][j] = '.';
            else if(arr[i][j] == 'O') holeX = i, holeY = j;
        }
    }
    queue<Ball> q;
    q.push({rx,ry,bx,by, 0});
    visited[rx][ry][bx][by] = 1;

    while(!q.empty()){
        auto [rx,ry,bx,by,cnt] = q.front();
        q.pop();
        
        if(cnt == 10) continue;

        for(int d = 0; d < 4; d++){
            auto [nrx,nry] = trial(rx,ry,d);
            auto [nbx,nby] = trial(bx,by,d);

            if(nbx == holeX && nby == holeY) continue;
            if(nrx == holeX && nry == holeY){
                cout << cnt+1;
                return 0;
            }

            if(nrx == nbx && nry == nby){
                int tmpR = abs(nrx-rx)+abs(nry-ry);
                int tmpB = abs(nbx-bx)+abs(nby-by);
                if(tmpR > tmpB) nrx -= dx[d], nry -= dy[d];
                else nbx -= dx[d], nby -= dy[d];
                
            }

            if(!visited[nrx][nry][nbx][nby]){
                visited[nrx][nry][nbx][nby] = 1;
                q.push({nrx,nry,nbx,nby,cnt+1});
            }
        }
    }
    cout << -1;
}