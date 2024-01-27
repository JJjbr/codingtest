#include <iostream>
#include <string>

using namespace std;

bool isPrime(int n)
{
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

bool isPalindrome(string num, int n)
{
	int cnt = 0;
	for (int i = 0; i < n / 2; i++)
	{
		if (num[i] == num[n - i - 1])
			cnt++;
	}
	if (cnt == n / 2) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	// Find answer
	string num;
	if (N == 1) N++;
	while (true)
	{
		// Change int to string
		num = to_string(N);
		// Check number
		if (isPalindrome(num, num.size()) && isPrime(N))
		{
			cout << N;
			break;
		}
		N++;
	}
	return 0;
}
