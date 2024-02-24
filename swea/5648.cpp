#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Info {
	int x, y, dir, energy;
};

struct Target {
	int a, b;
	double dist;
	bool operator<(Target right) const {
		if (dist == right.dist) {
			if (a == right.a) return b > right.b;
			return a > right.a;
		}
		return dist > right.dist;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, N;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// 입력
		cin >> N;
		int x, y, d, K;
		vector<Info> map;
		for (int i = 0; i < N; i++) {
			cin >> x >> y >> d >> K;
			map.push_back({ x, y, d, K });
		}

		// 원자 소멸 시뮬레이션
		// 충돌 가능성이 있는 원자들 저장
		priority_queue<Target> pq;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (map[i].y == map[j].y && abs(map[i].dir - map[j].dir) == 1) {
					if (map[i].dir == 2 && map[j].dir == 3 && map[i].x > map[j].x) {
						pq.push({ i, j, (map[i].x - map[j].x) / 2.0 });
					}
					else if (map[i].dir == 3 && map[j].dir == 2 && map[i].x < map[j].x) {
						pq.push({ i, j, (map[j].x - map[i].x) / 2.0 });
					}
				}
				else if (map[i].x == map[j].x && abs(map[i].dir - map[j].dir) == 1) {
					if (map[i].dir == 1 && map[j].dir == 0 && map[i].y > map[j].y) {
						pq.push({ i, j, (map[i].y - map[j].y) / 2.0 });
					}
					else if (map[i].dir == 0 && map[j].dir == 1 && map[i].y < map[j].y) {
						pq.push({ i, j, (map[j].y - map[i].y) / 2.0 });
					}
				}
				else if (abs(map[i].y - map[j].y) == abs(map[i].x - map[j].x)) {
					if (map[i].x < map[j].x && map[i].y > map[j].y) {
						if (map[i].dir == 3 && map[j].dir == 0) {
							pq.push({ i, j, fabs(map[i].y - map[j].y) });
						}
						else if (map[i].dir == 1 && map[j].dir == 2) {
							pq.push({ i, j, fabs(map[i].y - map[j].y) });
						}
					}
					else if (map[i].x > map[j].x && map[i].y < map[j].y) {
						if (map[i].dir == 0 && map[j].dir == 3) {
							pq.push({ i, j, fabs(map[i].y - map[j].y) });
						}
						else if (map[i].dir == 2 && map[j].dir == 1) {
							pq.push({ i, j, fabs(map[i].y - map[j].y) });
						}
					}
					else if (map[i].x < map[j].x && map[i].y < map[j].y) {
						if (map[i].dir == 0 && map[j].dir == 2) {
							pq.push({ i, j, fabs(map[i].y - map[j].y) });
						}
						else if (map[i].dir == 3 && map[j].dir == 1) {
							pq.push({ i, j, fabs(map[i].y - map[j].y) });
						}
					}
					else if (map[i].x > map[j].x && map[i].y > map[j].y) {
						if (map[i].dir == 2 && map[j].dir == 0) {
							pq.push({ i, j, fabs(map[i].y - map[j].y) });
						}
						else if (map[i].dir == 1 && map[j].dir == 3) {
							pq.push({ i, j, fabs(map[i].y - map[j].y) });
						}
					}
				}
			}
		}

		// 원자 충돌(소멸) 및 에너지 방출
		int total = 0;
		while (!pq.empty()) {
			Target now = pq.top();
			pq.pop();

			if (map[now.a].energy == 0 || map[now.b].energy == 0) continue;

			// 충돌한 원자들(A, B)의 에너지 합
			total += map[now.a].energy;
			total += map[now.b].energy;
			// 소멸한 원자들의 에너지는 0
			map[now.a].energy = 0;
			map[now.b].energy = 0;

			if (pq.empty()) break;

			Target next = pq.top();
			while (now.dist == next.dist) {
				if (map[next.a].energy > 0 || map[next.b].energy > 0) {
					total += map[next.a].energy;
					total += map[next.b].energy;
					map[next.a].energy = 0;
					map[next.b].energy = 0;
				}
				pq.pop();

				if (pq.empty()) break;
				next = pq.top();
			}
		}

		// 출력
		cout << "#" << t << " " << total << "\n";
	}
	return 0;
}
