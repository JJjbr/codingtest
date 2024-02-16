#include <iostream>
using namespace std;

int N;
char star[2200][2200];

void PrintSpace(int start, int cntN, int n)
{
	for (int i = 0; i < N; i++) {
		if (i % cntN == n) {
			for (int j = 0; j < n; j++) {
				star[start][i++] = ' ';
			}
			i--;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			star[i][j] = '*';
		}
	}
	for (int i = 0; i < N; i++) {
		int	cntN = 3;
		while (cntN <= N) {
			int n = cntN / 3;
			if (i % cntN == n) {
				for (int j = 0; j < n; j++) {
					PrintSpace(i + j, cntN, n);
				}
			}
			cntN *= 3;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << star[i][j];
		}
		cout << "\n";
	}
	return 0;
}
