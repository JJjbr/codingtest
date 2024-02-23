#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, N, X;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// 입력
		cin >> N >> X;
		int map[22][22] = { 0, };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		// 활주로 건설
		// 가로
		int start = 0, end = 0, runway = 0;
		for (int i = 0; i < N; i++) {
			start = 0; end = 0;
			while (start <= end) {
				while (map[i][start] == map[i][end]) end++;
				if (map[i][end] == 0) {
					runway++;
					break;
				}
				if (abs(map[i][start] - map[i][end]) != 1) break;
				if (map[i][start] < map[i][end]) {
					if (end - start < X) break;
					start = end;
				}
				else {
					start = end;
					while (map[i][start] == map[i][end]) end++;
					if (map[i][start - 1] < map[i][end]) break;
					if (map[i][end] == 0) {
						if (end - start < X) break;
						runway++;
						break;
					}
					if (map[i][start - 1] - map[i][end] == 0) {
						if (end - start < X * 2) break;
						start = end;
					}
					else if (map[i][start - 1] - map[i][end] == 2) {
						if (end - start < X) break;
						start = end - 1;
					}
					else {
						break;
					}
				}
			}
		}
		
		// 세로
		for (int i = 0; i < N; i++) {
			start = 0; end = 0;
			while (start <= end) {
				while (map[start][i] == map[end][i]) end++;
				if (map[end][i] == 0) {
					runway++;
					break;
				}
				if (abs(map[start][i] - map[end][i]) != 1) break;
				if (map[start][i] < map[end][i]) {
					if (end - start < X) break;
					start = end;
				}
				else {
					start = end;
					while (map[start][i] == map[end][i]) end++;
					if (map[start - 1][i] < map[end][i]) break;
					if (map[end][i] == 0) {
						if (end - start < X) break;
						runway++;
						break;
					}
					if (map[start - 1][i] - map[end][i] == 0) {
						if (end - start < X * 2) break;
						start = end;
					}
					else if (map[start - 1][i] - map[end][i] == 2) {
						if (end - start < X) break;
						start = end - 1;
					}
					else {
						break;
					}
				}
			}
		}

		// 출력
		cout << "#" << t << " " << runway << "\n";
	}
	return 0;
}
