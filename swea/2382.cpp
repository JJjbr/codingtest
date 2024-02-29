#include <iostream>
#include <queue>
using namespace std;

struct Info {
	int y, x, n, d;
};

struct Winner {
	int n, d;
	bool operator<(Winner right) const {
		return n < right.n;
	}
};

int dir[5][2] = { {0,0},{-1,0},{1,0},{0,-1},{0,1} };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, N, M, K;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		Info micro[1002];
		int y, x, n, d;
		for (int i = 0; i < K; i++) {
			cin >> y >> x >> n >> d;
			micro[i] = { y,x,n,d };
		}
		priority_queue<Winner> pq[102][102];
		bool visited[102][102] = { 0, };
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < K; j++) {
				visited[micro[j].y][micro[j].x] = false;
				if (micro[j].n == 0) continue;
				int ny = micro[j].y + dir[micro[j].d][0];
				int nx = micro[j].x + dir[micro[j].d][1];
				if (ny == 0) {
					micro[j].d = 2;
					micro[j].n /= 2;
				}
				else if (ny == N - 1) {
					micro[j].d = 1;
					micro[j].n /= 2;
				}
				else if (nx == 0) {
					micro[j].d = 4;
					micro[j].n /= 2;
				}
				else if (nx == N - 1) {
					micro[j].d = 3;
					micro[j].n /= 2;
				}
				pq[ny][nx].push({ micro[j].n, micro[j].d });
				micro[j].y = ny;
				micro[j].x = nx;
			}
			for (int j = 0; j < K; j++) {
				if (micro[j].n == 0) continue;
				if (visited[micro[j].y][micro[j].x]) {
					micro[j].n = 0;
					continue;
				}
				visited[micro[j].y][micro[j].x] = true;
				if (pq[micro[j].y][micro[j].x].size() > 1) {
					micro[j].n = 0;
					micro[j].d = pq[micro[j].y][micro[j].x].top().d;
					while (!pq[micro[j].y][micro[j].x].empty()) {
						Winner now = pq[micro[j].y][micro[j].x].top();
						pq[micro[j].y][micro[j].x].pop();
						micro[j].n += now.n;
					}
				}
				else {
					pq[micro[j].y][micro[j].x].pop();
				}
			}
		}
		int ans = 0;
		for (int j = 0; j < K; j++) {
			if (micro[j].n == 0) continue;
			ans += micro[j].n;
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
