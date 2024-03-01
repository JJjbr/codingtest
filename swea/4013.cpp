#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, K;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// 입력
		cin >> K;
		int magnet[5] = { 0, };
		int input;
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> input;
				magnet[i] <<= 1;
				if (input) {
					magnet[i] |= 1;
				}
			}
		}
		pair<int, int> v[22];
		for (int i = 0; i < K; i++) {
			cin >> v[i].first >> v[i].second;
		}

		// 자석
		for (int i = 0; i < K; i++) {
			int rotation[5] = { 0, };
			rotation[v[i].first] = v[i].second;
			for (int j = v[i].first + 1; j <= 4; j++) {
				if ((magnet[j - 1] & 0b00100000) != ((magnet[j] & 0b00000010) << 4)) {
					rotation[j] = -rotation[j - 1];
				}
				else {
					break;
				}
			}
			for (int j = v[i].first - 1; j > 0; j--) {
				if ((magnet[j] & 0b00100000) != ((magnet[j + 1] & 0b00000010) << 4)) {
					rotation[j] = -rotation[j + 1];
				}
				else {
					break;
				}
			}
			for (int j = 1; j <= 4; j++) {
				if(rotation[j] == 0) continue;
				if (rotation[j] == 1) {
					int rot = (magnet[j] & 1);
					magnet[j] >>= 1;
					magnet[j] |= (rot << 7);
				}
				else {
					int rot = (magnet[j] & 0b10000000) ? 1 : 0;
					magnet[j] <<= 1;
					magnet[j] |= rot;
					magnet[j] &= 0b011111111;
				}
			}
		}

		// 출력
		int ans = 0;
		for (int i = 0; i < 4; i++) {
			if (magnet[i + 1] & 0b10000000) ans += (1 << i);
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
