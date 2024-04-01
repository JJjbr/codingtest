#include <iostream>
using namespace std;

int num[100002];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		num[i] += num[i - 1];
	}
	int start = 0, end = 0;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		cout << num[end] - num[start - 1] << "\n";
	}
	return 0;
}
