#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	
	vector<int> v;
	priority_queue<int, vector<int>, greater<int>> q;
	int S, T;
	for (int i = 0; i < N; i++)
	{
		cin >> S >> T;
		v.push_back(S);
		q.push(T);
	}
	sort(v.begin(), v.end());

	for (int i = 1; i < N; i++)
	{
		if (v[i] >= q.top())
		{
			q.pop();
		}
	}
	cout << q.size();

	return 0;
}
