#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int a)
{
	for (int i = 2; i*i <= a; i++)
	{
		if (a % i == 0) return false;
	}
	return true;
}

long long gcd(long long a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long lcm(long long a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	int N;
	cin >> N;
	int A;
	vector<int> prime;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		if(isPrime(A)) prime.push_back(A);
	}

	if (prime.empty())
	{
		cout << -1;
	}
	else
	{
		long long answer = prime[0];
		for (int i = 1; i < prime.size(); i++)
		{
			answer = lcm(answer, prime[i]);
		}
		cout << answer;
	}
	return 0;
}
