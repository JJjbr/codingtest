#include <iostream>
using namespace std;

int map[1026][1026];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (j > 1) {
				map[i][j] += map[i][j - 1];
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] += map[i - 1][j];
		}
	}
	int x1, y1, x2, y2, sum;
	for (int m = 0; m < M; m++) {
		cin >> x1 >> y1 >> x2 >> y2;
		sum = map[x2][y2];
		if (y1 > 1) {
			sum -= map[x2][y1 - 1];
		}
		if (x1 > 1) {
			sum -= map[x1 - 1][y2];
		}
		if (x1 > 1 && y1 > 1) {
			sum += map[x1 - 1][y1 - 1];
		}
		cout << sum << "\n";
	}
	return 0;
}
