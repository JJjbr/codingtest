#include <iostream>
#include <queue>
using namespace std;

struct Coord {
	int y, x, t;
};

int dir[8][4][2] = { {0,0,0,0,0,0,0,0}, {-1,0,0,1,1,0,0,-1}, {-1,0,0,0,1,0,0,0}, {0,0,0,1,0,0,0,-1}, 
					{-1,0,0,1,0,0,0,0}, {0,0,0,1,1,0,0,0}, {0,0,0,0,1,0,0,-1}, {-1,0,0,0,0,0,0,-1} };
bool can_dir[4][8] = { { 0, 1, 1, 0, 0, 1, 1, 0 }, { 0, 1, 0, 1, 0, 0, 1, 1 },
						{ 0, 1, 1, 0, 1, 0, 0, 1 }, { 0, 1, 0, 1, 1, 1, 0, 0 } };
bool can_link[8][4] = { {0, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, 
						{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {1, 0, 0, 1} };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, N, M, R, C, L;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> R >> C >> L;
		int map[52][52] = { 0, };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}

		bool visited[52][52] = { 0, };
		queue<Coord> q;
		q.push({ R, C, 1 });
		int ans = 0;
		while (!q.empty()) {
			Coord now = q.front();
			q.pop();

			if (visited[now.y][now.x]) continue;
			visited[now.y][now.x] = true;

			if (now.t - 1 == L) break;
			ans++;

			for (int i = 0; i < 4; i++) {
				int ny = now.y + dir[map[now.y][now.x]][i][0];
				int nx = now.x + dir[map[now.y][now.x]][i][1];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
				if (map[ny][nx] == 0) continue;
				if (can_link[map[now.y][now.x]][i] && can_dir[i][map[ny][nx]]) {
					q.push({ ny, nx, now.t + 1 });
				}
			}
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
