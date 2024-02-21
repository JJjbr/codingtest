#include <iostream>
#include <queue>
using namespace std;

struct Coord {
	int y, x, num;
};

int N, W, H;
int map[17][14];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int ans = 1000;
bool all_empty;

int removeBlock(int sy, int sx, int cnt) {
	queue<Coord> q;
	q.push({ sy, sx, map[sy][sx] });
	map[sy][sx] = 0;
	cnt--;
	while (!q.empty()) {
		Coord now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < now.num; j++) {
				int ny = now.y + dy[i] * j;
				int nx = now.x + dx[i] * j;
				if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
				if (map[ny][nx] == 0) continue;
				q.push({ ny, nx, map[ny][nx] });
				map[ny][nx] = 0;
				cnt--;
			}
		}
	}
	queue<int> remain;
	for (int j = 0; j < W; j++) {
		for (int i = H - 1; i >= 0; i--) {
			if (map[i][j] > 0) {
				remain.push(map[i][j]);
				map[i][j] = 0;
			}
		}
		int i = H - 1;
		while (!remain.empty()) {
			map[i--][j] = remain.front();
			remain.pop();
		}
	}
	return cnt;
}

void repeatRemove(int n, int cnt) {
	if (n == N) {
		if (cnt < ans) ans = cnt;
		return;
	}
	if (cnt == 0) {
		ans = 0;
		all_empty = true;
		return;
	}
	int copy_map[17][14] = { 0, };
	int save_cnt = 0;
	for (int i = 0; i < W; i++) {
		bool flag = false;
		for (int j = 0; j < H; j++) {
			if (map[j][i] == 0) continue;
			flag = true;
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					copy_map[i][j] = map[i][j];
				}
			}
			save_cnt = cnt;
			cnt = removeBlock(j, i, cnt);
			break;
		}
		if (!flag) continue;
		repeatRemove(n + 1, cnt);
		if (all_empty) return;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				map[i][j] = copy_map[i][j];
			}
		}
		cnt = save_cnt;
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		ans = 1000;
		all_empty = false;
		cin >> N >> W >> H;
		int cnt = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
				if (map[i][j] > 0) cnt++;
			}
		}
		repeatRemove(0, cnt);
		cout << '#' << t << ' ' << ans << '\n';
	}
	return 0;
}
