#include <iostream>
#include <algorithm>
using namespace std;

int n;
int forest[502][502];
int cost[502][502];
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

int getPath(int y, int x) {
	if (cost[y][x] > 0) return cost[y][x];
	cost[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (forest[y][x] <= forest[ny][nx]) continue;
		cost[y][x] = max(cost[y][x], getPath(ny, nx) + 1);
	}
	return cost[y][x];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> forest[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, getPath(i, j));
		}
	}
	cout << ans << "\n";
	return 0;
}
