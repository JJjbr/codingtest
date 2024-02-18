#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		string W;
		int K;
		cin >> W >> K;
		vector<int> alphabet[26];
		for (int i = 0; i < W.size(); i++) {
			alphabet[W[i] - 'a'].push_back(i);
		}
		int min_string = 10001, max_string = 0;
		for (int i = 0; i < 26; i++) {
			if (alphabet[i].size() < K) continue;
			int start = 0;
			for (int j = K - 1; j < alphabet[i].size(); j++) {
				min_string = min(alphabet[i][j] - alphabet[i][start] + 1, min_string);
				max_string = max(alphabet[i][j] - alphabet[i][start] + 1, max_string);
				start++;
			}
		}
		if (min_string == 10001) {
			cout << -1 << "\n";
		}
		else {
			cout << min_string << ' ' << max_string << "\n";
		}
	}
	return 0;
}
