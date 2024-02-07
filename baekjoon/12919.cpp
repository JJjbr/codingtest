#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;
bool same;

bool checkSame(string new_S)
{
	string cmp_T;
	int l = T.size() - new_S.size();
	for (int i = 0; i <= l; i++) {
		cmp_T = T.substr(i, new_S.size());
		if (!new_S.compare(cmp_T)) {
			return true;
		}
	}
	return false;
}

bool checkSameRev(string new_S)
{
	string cmp_T;
	int l = T.size() - new_S.size();
	reverse(new_S.begin(), new_S.end());
	for (int i = 0; i <= l; i++) {
		cmp_T = T.substr(i, new_S.size());
		if (!new_S.compare(cmp_T)) {
			return true;
		}
	}
	return false;
}

void checkChange(string new_S)
{
	if (new_S.size() == T.size()) {
		if (!new_S.compare(T)) {
			same = true;
		}
	}

	if (!checkSame(new_S) && !checkSameRev(new_S)) {
		return;
	}

	checkChange(new_S + 'A');

	new_S += 'B';
	reverse(new_S.begin(), new_S.end());
	checkChange(new_S);
	reverse(new_S.begin(), new_S.end());
	new_S.pop_back();
}

int main()
{
	cin >> S >> T;
	checkChange(S);
	cout << same;
	return 0;
}
