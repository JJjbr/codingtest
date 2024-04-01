#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Coord {
	int y, x;
};

struct Info {
	int dist, chicken;
};

int N, M, h, c, ans = INT_MAX;
int map[52][52];
Info dists[102][15];
Coord house[102];
Coord chicken[15];
int path[15];

bool compare(Info left, Info right) {
	return left.dist < right.dist;
}

int calcDistSum() {
	int sum = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < c; j++) {
			if (!path[dists[i][j].chicken]) continue;
			sum += dists[i][j].dist;
			break;
		}
	}
	return sum;
}

void getClosestDist(int n, int cnt) {
	if (cnt >= M) {
		int sum = calcDistSum();
		if (sum < ans) ans = sum;
		return;
	}
	if (n >= c) return;
	for (int i = 0; i < 2; i++) {
		path[n] = i;
		if(i == 1) getClosestDist(n + 1, cnt + 1);
		else getClosestDist(n + 1, cnt);
		path[n] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				house[h++] = { i, j };
			}
			else if (map[i][j] == 2) {
				chicken[c++] = { i, j };
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < c; j++) {
			dists[i][j] = { abs(house[i].y - chicken[j].y) + abs(house[i].x - chicken[j].x), j };
		}
		sort(dists[i], dists[i] + c, compare);
	}
	getClosestDist(0, 0);
	cout << ans << "\n";
	return 0;
}
