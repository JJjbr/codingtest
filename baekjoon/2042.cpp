#include <iostream>
#define MAX 1000002

using namespace std;

long long num[MAX];
long long tree[MAX * 4];

long long init(int start, int end, int node) {
	if (start == end) return tree[node] = num[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long dif) {
	if (index > end || index < start) return;
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	init(0, N - 1, 1);

	long long a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		// b번째 수를 c로 바꾼다.
		if (a == 1) {
			update(0, N - 1, 1, b - 1, c - num[b - 1]);
			num[b - 1] = c;
		}
		// b번째 수부터 c번째 수까지 합을 구한다.
		else if (a == 2) {
			cout << sum(0, N - 1, 1, b - 1, c - 1) << "\n";
		}
	}
	return 0;
}
