#include <iostream>
#include <algorithm>

using namespace std;

int dp[101][100001] = { 0, };

struct Bag {
	int w, v;
};

bool cmp(Bag l, Bag r)
{
	return l.w < r.w;
}

int main()
{
	int N, K;
	cin >> N >> K;
	Bag bag[101] = { 0, };
	for (int i = 1; i <= N; i++)
	{
		cin >> bag[i].w >> bag[i].v;
	}
	sort(bag, bag + N + 1, cmp);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (bag[i].w <= j) {
				dp[i][j] = max(dp[i - 1][j], bag[i].v + dp[i - 1][j - bag[i].w]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[N][K];
	return 0;
}
