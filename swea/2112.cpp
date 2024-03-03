#include <iostream>
#include <cstring>
using namespace std;

int D, W, K;
int film[15][22];
int path[15];
int ans;

bool checkPass() {
	for (int i = 0; i < W; i++) {
		int same = 1, pre = 0;
		for (int j = 1; j < D; j++) {
			if (path[j - 1] < 0) {
				pre = film[j - 1][i];
			}
			else {
				pre = path[j - 1];
			}

			if (path[j] < 0) {
				if (pre == film[j][i]) {
					same++;
				}
				else {
					same = 1;
				}
			}
			else {
				if (pre == path[j]) {
					same++;
				}
				else {
					same = 1;
				}
			}
			if (same == K) break;
		}
		if (same < K) return false;
	}
	return true;
}

void dfs(int n, int cnt) {
	if (cnt >= ans) return;
	if (checkPass()) {
		if (ans > cnt) ans = cnt;
	}
	if (n >= D) {
		return;
	}
	for (int i = -1; i <= 1; i++) {
		path[n] = i;
		if (i >= 0) dfs(n + 1, cnt + 1);
		else dfs(n + 1, cnt);
		path[n] = -1;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// 초기화
		memset(path, -1, sizeof(path));
		ans = 20;

		// 입력
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> film[i][j];
			}
		}

		// 보호 필름
		dfs(0, 0);

		// 출력
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
