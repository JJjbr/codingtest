#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Coord {
	int y, x, life, alive;
	bool operator<(Coord right) const {
		return alive < right.alive;
	}
};

int N, M, K;
int map[1000][1000];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(map, 0, sizeof(map));
		priority_queue<Coord> pq[302];

		// 입력
		cin >> N >> M >> K;
		for (int i = 500; i < N + 500; i++) {
			for (int j = 500; j < M + 500; j++) {
				cin >> map[i][j];
				if (map[i][j] > 0) {
					pq[0].push({ i, j, map[i][j], map[i][j] });
				}
			}
		}
		
		// 줄기 세포 배양
		for (int k = 0; k < K; k++) {
			while (!pq[k].empty()) {
				Coord now = pq[k].top();
				pq[k].pop();

				// 활성 상태 시작 -> 생명력 = 0
				if (now.life - 1 == 0) {
					pq[k + 1].push({ now.y, now.x, 0, now.alive });
				}
				// 비활성 상태 -> 생명력 > 0
				else if (now.life - 1 > 0) {
					pq[k + 1].push({ now.y, now.x, now.life - 1, now.alive });
				}
				// 살아있는 상태 (활성 상태) -> 남은 시간 카운트 다운
				else {
					// 번식 -> 첫 1시간
					if (now.life == 0) {
						for (int j = 0; j < 4; j++) {
							int ny = now.y + dy[j];
							int nx = now.x + dx[j];
							if (map[ny][nx] != 0) continue;
							pq[k + 1].push({ ny, nx, now.alive, now.alive });
							map[ny][nx] = now.alive;
						}
					}

					if (now.alive - 1 == 0) {
						// 죽은 상태 -> 생명력 = -1
						map[now.y][now.x] = -1;
					}
					else {
						pq[k + 1].push({ now.y, now.x, -1, now.alive - 1 });
					}
				}
			}
		}

		// 출력
		cout << "#" << t << " " << pq[K].size() << "\n";
	}
	return 0;
}
