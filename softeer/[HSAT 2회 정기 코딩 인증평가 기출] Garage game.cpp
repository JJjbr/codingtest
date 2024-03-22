#include<iostream>
#include<queue>

#define ROW 47
#define COL 17

using namespace std;

struct Coord{
    int y, x;
};

int N, minN, maxN;
int map[ROW][COL];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ans;

void downMap(){
    for(int x=0; x<N; x++){
        for(int y=maxN-1; y>0; y--){
            if(!map[y][x]) {
                int idx = y - 1;
                while(!map[idx][x]) {
                    idx--;
                    if(idx < 0) break;
                }
                if(idx >= 0){
                    map[y][x] = map[idx][x];
                    map[idx][x] = 0;
                }
            }
        }
    }
}

int sameNum(int sy, int sx, bool visited[ROW][COL]){
    int num = map[sy][sx];
    queue<Coord> q;
    q.push({sy, sx});
    map[sy][sx] = 0;
    visited[sy][sx] = true;
    int score = 0, minx = sx, miny = sy, maxx = sx, maxy = sy;
    while(!q.empty()){
        Coord now = q.front();
        q.pop();
        score++;
        if(miny > now.y) miny = now.y;
        else if(maxy < now.y) maxy = now.y;
        if(minx > now.x) minx = now.x;
        else if(maxx < now.x) maxx = now.x;
        for(int i=0; i<4; i++){
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if(ny<minN || ny>=maxN || nx<0 || nx>=N) continue;
            if(!map[ny][nx] || map[ny][nx] != num) continue;
            q.push({ny, nx});
            map[ny][nx] = 0;
            visited[ny][nx] = true;
        }
    }
    int area = (maxx + 1 - minx) * (maxy + 1 - miny);
    downMap();
    return score + area;
}

int getSum(int sy, int sx){
    int num = map[sy][sx];
    queue<Coord> q;
    q.push({sy, sx});
    map[sy][sx] = 0;
    int score = 0, minx = sx, miny = sy, maxx = sx, maxy = sy;
    while(!q.empty()){
        Coord now = q.front();
        q.pop();
        score++;
        if(miny > now.y) miny = now.y;
        else if(maxy < now.y) maxy = now.y;
        if(minx > now.x) minx = now.x;
        else if(maxx < now.x) maxx = now.x;
        for(int i=0; i<4; i++){
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if(ny<minN || ny>=maxN || nx<0 || nx>=N) continue;
            if(!map[ny][nx] || map[ny][nx] != num) continue;
            q.push({ny, nx});
            map[ny][nx] = 0;
        }
    }
    int area = (maxx + 1 - minx) * (maxy + 1 - miny);
    return score + area;
}

void getScore(int sum, int n){
    if(n == 2){
        bool tmp[ROW][COL] = {0,};
        for(int i=0; i<maxN; i++){
            for(int j=0; j<N; j++){
                tmp[i][j] = map[i][j];
            }
        }
        for(int y=minN; y<maxN; y++){
            for(int x=0; x<N; x++){
                if(!map[y][x]) continue;
                int res = sum + getSum(y, x);
                if(ans < res) ans = res;
            }
        }
        for(int i=0; i<maxN; i++){
            for(int j=0; j<N; j++){
                map[i][j] = tmp[i][j];
            }
        }
        return;
    }
    bool tmp_v[ROW][COL] = {0,};
    for(int y=minN; y<maxN; y++){
        for(int x=0; x<N; x++){
            if(tmp_v[y][x]) continue;
            int tmp[ROW][COL] = {0,};
            for(int i=0; i<maxN; i++){
                for(int j=0; j<N; j++){
                    tmp[i][j] = map[i][j];
                }
            }
            getScore(sum + sameNum(y, x, tmp_v), n + 1);
            for(int i=0; i<maxN; i++){
                for(int j=0; j<N; j++){
                    map[i][j] = tmp[i][j];
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    cin >> N;
    minN = N*2;
    maxN = N*3;
    for(int i=0; i<maxN; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
    getScore(0, 0);
    cout << ans << "\n";
    return 0;
}
