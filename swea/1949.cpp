#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Coord {
	int y, x, h, dist;
};

int N, K;
int map[10][10];
int visited[10][10];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int ans;

void dfs(Coord now, int k) {

	if (ans < now.dist) {
		ans = now.dist;
	}
	for (int i = 0; i < 4; i++) {
		int ny = now.y + dy[i];
		int nx = now.x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (visited[ny][nx]) continue;
		int nheight = map[ny][nx];
		if (nheight >= now.h) {
			if (nheight - k < now.h) {
				nheight = now.h - 1;
				visited[ny][nx] = true;
				dfs({ ny, nx, nheight, now.dist + 1 }, 0);
				visited[ny][nx] = false;
			}
			else {
				continue;
			}
		}
		else {
			visited[ny][nx] = true;
			dfs({ ny, nx, nheight, now.dist + 1 }, k);
			visited[ny][nx] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int max_height = 0;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		ans = 0;

		// 입력
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] > max_height) {
					max_height = map[i][j];
				}
			}
		}

		// 가장 높은 봉우리의 좌표 저장
		queue<Coord> start;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == max_height) {
					start.push({ i, j, max_height, 1 });
				}
			}
		}

		// 등산로 경로 탐색
		while (!start.empty()) {
			visited[start.front().y][start.front().x] = true;
			dfs(start.front(), K);
			visited[start.front().y][start.front().x] = false;
			start.pop();
		}

		// 출력
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
