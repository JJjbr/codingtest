#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> map[13][13];
int one[102];
int two[102];
int dir[5][2] = { {0, 0},{-1, 0},{0, 1},{1, 0},{0, -1} };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, M, A;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// 초기화
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 13; j++) {
				map[i][j].clear();
				map[i][j].push_back({ 0, -1 });
			}
		}

		// 입력
		cin >> M >> A;
		for (int i = 0; i < M; i++) {
			cin >> one[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> two[i];
		}
		int X, Y, C, P;
		for (int i = 0; i < A; i++) {
			cin >> X >> Y >> C >> P;
			for (int x = -C; x <= C; x++) {
				if (X + x > 0 && X + x <= 10) {
					map[Y][X + x].push_back({ P, i });
				}
			}
			for (int y = 1; y <= C; y++) {
				for (int x = -C + y; x <= C - y; x++) {
					if (Y + y > 0 && Y + y <= 10 && X + x > 0 && X + x <= 10) {
						map[Y + y][X + x].push_back({ P, i });
					}
					if (Y - y > 0 && Y - y <= 10 && X + x > 0 && X + x <= 10) {
						map[Y - y][X + x].push_back({ P, i });
					}
				}
			}
		}
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				sort(map[i][j].begin(), map[i][j].end(), greater<pair<int, int>>());
			}
		}

		// 충전
		int ay = 1, ax = 1, by = 10, bx = 10;
		int ans = (map[ay][ax][0].first + map[by][bx][0].first);
		for (int i = 0; i < M; i++) {
			ay = ay + dir[one[i]][0];
			ax = ax + dir[one[i]][1];

			by = by + dir[two[i]][0];
			bx = bx + dir[two[i]][1];

			if (map[ay][ax].size() == 1 && map[by][bx].size() == 1) continue;
			if (ay == by && ax == bx) {
				if (map[ay][ax].size() == 2) {
					ans += map[ay][ax][0].first;
				}
				else {
					ans += (map[ay][ax][0].first + map[ay][ax][1].first);
				}
			}
			else if (map[ay][ax][0].second == map[by][bx][0].second) {
				if (map[ay][ax][1].second == map[by][bx][1].second) {
					ans += (map[ay][ax][0].first + map[by][bx][1].first);
				}
				else if (map[ay][ax][1] >= map[by][bx][1]) {
					ans += (map[ay][ax][1].first + map[by][bx][0].first);
				}
				else {
					ans += (map[ay][ax][0].first + map[by][bx][1].first);
				}
			}
			else {
				ans += (map[ay][ax][0].first + map[by][bx][0].first);
			}
		}

		// 출력
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
