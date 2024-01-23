#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		int a_ = abs(a), b_ = abs(b);
		if (a_ == b_) return a > b;
		return a_ > b_;
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, cmp> q;
	int x;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x)
		{
			q.push(x);
		}
		else
		{
			if (!q.empty()) {
				cout << q.top() << "\n";
				q.pop();
			}
			else {
				cout << 0 << "\n";
			}
		}
	}
	return 0;
}
