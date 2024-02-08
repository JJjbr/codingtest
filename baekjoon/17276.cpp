#include <iostream>
#include <queue>
using namespace std;

struct Coord {
	int y, x, num;
};

int n, d;
int map[500][500];
int dy[8] = { -1,-1,-1,0,1,1,1,0 };
int dx[8] = { -1,0,1,1,1,0,-1,-1 };

void rotationMapCW(int center, int angle)
{
	for (int d = center; d > 0; d--) {
		queue<int> q;
		for (int i = 0; i < 8; i++) {
			int ny = center + dy[i] * d;
			int nx = center + dx[i] * d;
			q.push(map[ny][nx]);
		}
		int i = angle, y, x;
		while (!q.empty()) {
			y = center + dy[i] * d;
			x = center + dx[i] * d;
			map[y][x] = q.front();
			q.pop();
			i++;
			if (i >= 8) i = 0;
		}
	}
}

void rotationMapCCW(int center, int angle)
{
	for (int d = center; d > 0; d--) {
		queue<int> q;
		for (int i = 7; i >= 0; i--) {
			int ny = center + dy[i] * d;
			int nx = center + dx[i] * d;
			q.push(map[ny][nx]);
		}
		int i = 7 - angle, y, x;
		while (!q.empty()) {
			y = center + dy[i] * d;
			x = center + dx[i] * d;
			map[y][x] = q.front();
			q.pop();
			i--;
			if (i < 0) i = 7;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> d;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		if (d >= 0) {
			rotationMapCW(n / 2, (d / 45) % 8);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << map[i][j] << ' ';
				}
				cout << "\n";
			}
		}
		else {
			rotationMapCCW(n / 2, ((-d) / 45) % 8);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << map[i][j] << ' ';
				}
				cout << "\n";
			}
		}
	}
	return 0;
}
