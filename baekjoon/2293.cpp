#include <iostream>
#include <algorithm>

using namespace std;

int sum[10001];

int main()
{
	int n, k;
	cin >> n >> k;
	int cost[100];
	int tmp, a = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp <= k) cost[a++] = tmp;
	}
	sort(cost, cost + a);

	sum[0] = 1;
	for (int i = 0; i < a; i++)
	{
		for (int j = cost[i]; j <= k; j++)
		{
			sum[j] += sum[j - cost[i]];
		}
	}
	cout << sum[k];
	return 0;
}
