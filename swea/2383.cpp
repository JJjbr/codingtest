#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct People {
	int y, x;
};

struct Stairs {
	int y, x, k;
};

struct Info {
	int d, s;
	bool operator<(Info right) const {
		if (s == right.s) return d > right.d;
		return s > right.s;
	}
};

int N, P, S;
int map[12][12];
People people[12];
Stairs stairs[4];
int dist[12][2];
Info path[12];
int ans;

void func(int n) {
	if (n >= P) {
		priority_queue<Info> pq;
		for (int i = 0; i < P; i++) {
			pq.push({ path[i].d, path[i].s });
		}
		int s_one = 0, s_two = 0, i_one = 0, i_two = 0, total = 0;
		int dp[2][12] = { 0, };
		while (!pq.empty()) {
			Info now = pq.top();
			pq.pop();

			if (now.s == 0) {
				if (s_one >= 3) {
					if (dp[now.s][i_one - 3] > now.d) {
						dp[now.s][i_one] = dp[now.s][i_one - 3] + stairs[now.s].k;
					}
					else {
						dp[now.s][i_one] = now.d + stairs[now.s].k + 1;
						s_one--;
					}
				}
				else {
					dp[now.s][i_one] = now.d + stairs[now.s].k + 1;
					s_one++;
				}
				if (total < dp[now.s][i_one]) {
					total = dp[now.s][i_one];
				}
				i_one++;
			}
			else {
				if (s_two >= 3) {
					if (dp[now.s][i_two - 3] > now.d) {
						dp[now.s][i_two] = dp[now.s][i_two - 3] + stairs[now.s].k;
					}
					else {
						dp[now.s][i_two] = now.d + stairs[now.s].k + 1;
						s_two--;
					}
				}
				else {
					dp[now.s][i_two] = now.d + stairs[now.s].k + 1;
					s_two++;
				}
				if (total < dp[now.s][i_two]) {
					total = dp[now.s][i_two];
				}
				i_two++;
			}
			if (ans <= total) {
				return;
			}
		}
		if (ans > total) {
			ans = total;
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		path[n] = { dist[n][i], i };
		func(n + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		S = 0; P = 0; ans = INT_MAX;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					people[P++] = { i, j };
				}
				else if (map[i][j] > 1) {
					stairs[S++] = { i, j, map[i][j] };
				}
			}
		}
		for (int i = 0; i < P; i++) {
			dist[i][0] = abs(people[i].y - stairs[0].y) + abs(people[i].x - stairs[0].x);
			dist[i][1] = abs(people[i].y - stairs[1].y) + abs(people[i].x - stairs[1].x);
		}
		func(0);
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
