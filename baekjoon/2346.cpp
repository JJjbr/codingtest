#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int* balloon = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> balloon[i];
    }

    int idx = balloon[0] > 0 ? balloon[0] : N + balloon[0];
    balloon[0] = 0;
    cout << 1 << ' ' << idx + 1 << ' ';
    for (int i = 2; i < N; i++)
    {
        // find next index
        int cnt = 0, tmp = balloon[idx];
        balloon[idx] = 0;
        if (tmp > 0)
        {
            while (cnt < tmp)
            {
                idx++;
                if (idx >= N) idx = 0;
                if (balloon[idx] != 0) {
                    cnt++;
                }
            }
        }
        else
        {
            while (cnt > tmp)
            {
                idx--;
                if (idx < 0) idx = N - 1;
                if (balloon[idx] != 0) {
                    cnt--;
                }
            }
        }
        // print result
        cout << idx + 1 << ' ';
    }
    return 0;
}
