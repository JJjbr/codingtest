#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int K, cnt;
vector<int> num;
vector<int>* answer;

void find_tree(int n)
{
	if (n == K - 1) {
		answer[n].push_back(num[cnt++]);
		return;
	}
	find_tree(n + 1);
	answer[n].push_back(num[cnt++]);
	find_tree(n + 1);
}

int main()
{
	std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> K;
	answer = new vector<int>[K];
	int node_size = pow(2, K);
	num = vector<int>(node_size);
	for (int i = 0; i < node_size - 1; i++)
	{
		cin >> num[i];
	}

	find_tree(0);
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < answer[i].size(); j++)
		{
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
	delete[] answer;
	return 0;
}
