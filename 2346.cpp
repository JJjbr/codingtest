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
    cout << 1 << ' ';
    for (int i = 1; i < N; i++)
    {
        cout << idx + 1 << ' ';
        if (i >= N - 1) break;

        // set next index
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
    }
    return 0;
}