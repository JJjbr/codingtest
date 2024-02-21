#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Coord {
	int y, x;
};

struct Node {
	int a, b, cost;
};

int N, M;
int map[12][12];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int parent[10];
vector<Node> line;

bool compare(Node l, Node r) {
	return l.cost < r.cost;
}

void init(int n) {
	for (int i = 2; i <= n; i++) {
		parent[i] = i;
	}
}

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;
	parent[t2] = t1;
}

void bfs(int sy, int sx, int label) {
	queue<Coord> q;
	q.push({ sy, sx });
	map[sy][sx] = label;
	while (!q.empty()) {
		Coord now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (map[ny][nx] != 1) continue;
			map[ny][nx] = label;
			q.push({ ny, nx });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int label = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 1) continue;
			bfs(i, j, ++label);
		}
	}
	init(label);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) continue;
			for (int k = j + 1; k < M; k++) {
				if (map[i][j] == map[i][k]) break;
				if (map[i][k] >= 2) {
					if (k - j - 1 <= 1) break;
					line.push_back({ map[i][j], map[i][k], k - j - 1 });
					break;
				}
			}
		}
	}
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			if (map[i][j] == 0) continue;
			for (int k = i + 1; k < N; k++) {
				if (map[i][j] == map[k][j]) break;
				if (map[k][j] >= 2) {
					if (k - i - 1 <= 1) break;
					line.push_back({ map[i][j], map[k][j], k - i - 1 });
					break;
				}
			}
		}
	}
	sort(line.begin(), line.end(), compare);
	int result = 0, cnt = 0, tar = label - 2;
	for (int i = 0; i < line.size(); i++) {
		if (find(line[i].a) == find(line[i].b)) continue;
		setUnion(line[i].a, line[i].b);
		result += line[i].cost;
		cnt++;
		if (cnt == tar) break;
	}
	if (cnt < tar) cout << -1 << "\n";
	else cout << result << "\n";
	return 0;
}
