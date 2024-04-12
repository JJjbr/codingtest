#include <iostream>
#include <algorithm>
using namespace std;

struct Coord {
	int y, x;
};

int N, K;
Coord house[52];
Coord path[5];
int ans = 1e6;

void getDistance(int n, int s) {
	if (n >= K) {
		int max_dist = 0;
		for (int i = 0; i < N; i++) {
			int min_dist = 1e6;
			for (int j = 0; j < K; j++) {
				int dist = abs(house[i].y - path[j].y) + abs(house[i].x - path[j].x);
				min_dist = min(dist, min_dist);
			}
			max_dist = max(min_dist, max_dist);
		}
		ans = min(ans, max_dist);
		return;
	}
	for (int i = s; i < N; i++) {
		path[n] = house[i];
		getDistance(n + 1, i + 1);
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> house[i].x >> house[i].y;
	}
	getDistance(0, 0);
	cout << ans << "\n";
	return 0;
}
