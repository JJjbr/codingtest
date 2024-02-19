#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N, K;
		cin >> N >> K;
		string numbers;
		cin >> numbers;
		int rot_num = N / 4;
		priority_queue<int> pq;
		int side_num = rot_num, hex2dec = 0;
		for (int i = 0; i < rot_num; i++) {
			string side;
			for (int j = 0; j < 4; j++) {
				if (j == 3) {
					side = numbers.substr(N - i, i);
					side += numbers.substr(0, rot_num - i);
				}
				else {
					side = numbers.substr(side_num + rot_num * j, rot_num);
				}
				for (int k = 0; k < rot_num; k++) {
					int num = side[k] - '0';
					if (num > 9) num -= 7;
					hex2dec = (hex2dec << 4);
					hex2dec |= num;
				}
				pq.push(hex2dec);
				hex2dec = 0;
			}
			side_num--;
		}
		int cnt = 1, ans = pq.top();
		pq.pop();
		while (cnt < K) {
			if (pq.top() == ans) {
				pq.pop();
				continue;
			}
			ans = pq.top();
			pq.pop();
			cnt++;
		}
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
