#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Info {
	int y, x, money;
	bool operator<(Info right) const {
		return money < right.money;
	}
};

int N, M, C;
int honey[12][12];
int max_sum = 0;
bool visited[12];

void findMax(int y, int x, int num, int n, int xi) {
	if (n <= C) {
		if (max_sum < num) max_sum = num;
		if (n == C) return;
	}
	else return;
	for (int i = xi; i < M; i++) {
		if (visited[x + i]) continue;
		visited[x + i] = true;
		findMax(y, x, num + honey[y][x + i] * honey[y][x + i], n + honey[y][x + i], i);
		visited[x + i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> honey[i][j];
			}
		}
		
		priority_queue<Info> pq;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {
				memset(visited, 0, sizeof(visited));
				max_sum = 0;
				findMax(i, j, 0, 0, 0);
				pq.push({ i, j, max_sum });
			}
		}

		Info now = pq.top();
		pq.pop();
		int ans = now.money;
		while (!pq.empty()) {
			Info next = pq.top();
			pq.pop();

			if (now.y == next.y) {
				if (now.x < next.x) {
					if (now.x + M - 1 >= next.x) continue;
					ans += next.money;
					break;
				}
				else {
					if (now.x <= next.x + M - 1) continue;
					ans += next.money;
					break;
				}
			}
			else {
				ans += next.money;
				break;
			}
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
