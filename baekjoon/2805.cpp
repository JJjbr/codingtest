#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<long long> trees;

int bs(int start, int end) {
	long long mid = 0, cut_tree = 0, max_mid = -1;
	while (start <= end) {
		mid = (start + end) / 2;

		cut_tree = 0;
		for (int i = 0; i < trees.size(); i++) {
			if (trees[i] - mid > 0) {
				cut_tree += (trees[i] - mid);
			}
		}

		if (cut_tree == M) {
			return mid;
		}

		if (cut_tree > M) {
			max_mid = max(max_mid, mid);
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return max_mid;
}

int main()
{
	cin >> N >> M;
	trees = vector<long long>(N);
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
	}
	sort(trees.begin(), trees.end());
	cout << bs(0, trees[N - 1]);
	return 0;
}
