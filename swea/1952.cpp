#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int price[4];
		for (int i = 0; i < 4; i++) {
			cin >> price[i];
		}
		int dp[13] = { 0, };
		int plan;
		for (int i = 1; i <= 12; i++) {
			cin >> plan;
			if (plan > 0) dp[i] = plan * price[0];
		}
		for (int i = 1; i <= 12; i++) {
			if (dp[i] == 0) dp[i] = dp[i - 1];
			else {
				dp[i] = dp[i - 1] + min(dp[i], price[1]);
				dp[i] = min(dp[i], dp[i - 3] + price[2]);
			}
		}
		dp[12] = min(dp[12], price[3]);
		cout << "#" << t << " " << dp[12] << "\n";
	}
	return 0;
}
