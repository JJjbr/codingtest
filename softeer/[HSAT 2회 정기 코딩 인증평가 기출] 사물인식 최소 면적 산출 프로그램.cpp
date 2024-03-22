#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Coord{
    int y, x;
};

int N, K;
vector<Coord> map[22];
int miny, minx, maxy, maxx;
int min_area = 1e8;

void getArea(int n, int miny, int minx, int maxy, int maxx){
    int area = (maxy - miny) * (maxx - minx);
    if(area >= min_area) return;
    if(n > K){
        min_area = area;
        return;
    }
    for(int i=0; i<map[n].size(); i++){
        getArea(n + 1, min(miny, map[n][i].y), min(minx, map[n][i].x), max(maxy, map[n][i].y), max(maxx, map[n][i].x));
    }
}

int main(int argc, char** argv)
{
    cin >> N >> K;
    int x, y, k;
    for(int i=0; i<N; i++){
        cin >> x >> y >> k;
        map[k].push_back({y, x});
    }
    getArea(1, 2000, 2000, -2000, -2000);
    cout << min_area << "\n";
    return 0;
}
