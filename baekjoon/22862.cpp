#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> S(N);
	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
	}
	int ans = 0;
	int cnt = 0, k = 0;
	int start = 0, end = 0;
	while (start < N && end < N)
	{   
		// even
		if (S[end++] % 2 == 0) {
			cnt++;
		}
		// odd
		else {
			k++;
		}
		if (k == K) {
			while (end < N && S[end] % 2 == 0) {
				cnt++;
				end++;
			}
			ans = max(ans, cnt);
			if (end == N) break;
			while (k == K) {
				if (S[start] % 2 != 0) {
					k--;
				}
				else {
					cnt--;
				}
				start++;
			}
		}
	}
	if (ans == 0) ans = cnt;
	cout << ans;
	return 0;
}
