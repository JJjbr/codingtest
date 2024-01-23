#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	string exp;
	cin >> N >> exp;
	int num[26] = { 0, };
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	string op = "+-/*";
	vector<double> box;
	for (int i = 0; i < exp.length(); i++)
	{
		if (op.find(exp[i]) != string::npos)
		{
			double op2 = box.back();
			box.pop_back();
			double op1 = box.back();
			box.pop_back();
			if (exp[i] == '+')
				box.push_back(op1 + op2);
			else if (exp[i] == '-')
				box.push_back(op1 - op2);
			else if (exp[i] == '*')
				box.push_back(op1 * op2);
			else
				box.push_back(op1 / op2);
		}
		else
		{
			box.push_back(num[exp[i] - 'A']);
		}
	}
	printf("%.2f", box[0]);
	return 0;
}
