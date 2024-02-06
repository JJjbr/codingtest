#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Coord {
	int r, c;
};

int N, M;
int A[52][52];
queue<Coord> C;
bool visited[51][51];
int dr[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dc[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int ddr[4] = { -1, -1, 1, 1 };
int ddc[4] = { -1, 1, -1, 1 };

void moveCloud(int d, int s)
{
	Coord now;
	int l = C.size();
	for (int i = 0; i < l; i++) {
		now = C.front();
		C.pop();
		int nr = now.r + dr[d] * s;
		int nc = now.c + dc[d] * s;

		if (nr < 1) nr = N + nr;
		else if (nr > N) nr = nr - N;
		if (nc < 1) nc = N + nc;
		else if (nc > N) nc = nc - N;

		A[nr][nc]++;
		visited[nr][nc] = 1;
	}
}

void makeCloud()
{
	queue<Coord> q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j]) {
				for (int k = 0; k < 4; k++) {
					int tr = i + ddr[k];
					int tc = j + ddc[k];
					if (tr < 1 || tr > N || tc < 1 || tr > N) continue;
					if (A[tr][tc] > 0) {
						A[i][j]++;
					}
				}
			}
			if (A[i][j] >= 2) {
				if (!visited[i][j]) {
					C.push({ i, j });
					q.push({ i, j });
				}
			}
		}
	}
	while (!q.empty()) {
		Coord now = q.front();
		q.pop();
		A[now.r][now.c] -= 2;
	}
}

int countWater()
{
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cnt += A[i][j];
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	C.push({ N, 1 });
	C.push({ N, 2 });
	C.push({ N - 1, 1 });
	C.push({ N - 1, 2 });
	int d, s;
	for (int i = 0; i < M; i++) {
		cin >> d >> s;
		fill(visited[0], visited[51], 0);
		moveCloud(d - 1, s % N);
		makeCloud();
	}
	cout << countWater();
	return 0;
}
