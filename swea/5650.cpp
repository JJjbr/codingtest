#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N;
int map[102][102];
vector<pair<int, int>> wormhole[7];
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
bool finish;
int sy, sx, ans;
int direction[4][6] = { {2,2,1,3,2,2}, {3,3,3,2,0,3}, {0,1,0,0,3,0}, {1,0,2,1,1,1} };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// 초기화
		memset(map, 0, sizeof(map));
		ans = 0;
		for (int i = 0; i < 7; i++) {
			wormhole[i].clear();
		}
		
		// 입력
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 6 && map[i][j] <= 10) {
					wormhole[map[i][j] - 6].push_back({ i, j });
				}
			}
		}
		
		// 핀볼 게임
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] != 0) continue;
				for (int k = 0; k < 4; k++) {
					finish = false;
					sy = i;
					sx = j;

					int score = 0, y = i + dir[k][0], x = j + dir[k][1], d = k;
					while (y != sy || x != sx) {
						// 벽
						if (y < 0) {
							y = 0;
							d = direction[d][0];
							score++;
						}
						else if (x >= N) {
							x = N - 1;
							d = direction[d][0];
							score++;
						}
						else if (y >= N) {
							y = N - 1;
							d = direction[d][0];
							score++;
						}
						else if (x < 0) {
							x = 0;
							d = direction[d][0];
							score++;
						}
						// 블랙홀
						else if (map[y][x] == -1) {
							break;
						}
						else {
							// 빈 공간
							if (map[y][x] == 0) {
								y = y + dir[d][0];
								x = x + dir[d][1];
							}
							else {
								// 블록
								if (map[y][x] >= 1 && map[y][x] <= 5) {
									int nd = direction[d][map[y][x]];
									y = y + dir[nd][0];
									x = x + dir[nd][1];
									d = nd;
									score++;
								}
								// 웜홀
								else if (map[y][x] >= 6 && map[y][x] <= 10) {
									int num = map[y][x] - 6;
									if (wormhole[num][0].first == y && wormhole[num][0].second == x) {
										y = wormhole[num][1].first + dir[d][0];
										x = wormhole[num][1].second + dir[d][1];
									}
									else {
										y = wormhole[num][0].first + dir[d][0];
										x = wormhole[num][0].second + dir[d][1];
									}
								}
							}
						}
					}
					if (ans < score) ans = score;
				}
			}
		}
		
		// 출력
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
