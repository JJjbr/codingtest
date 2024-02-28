#include <iostream>
using namespace std;
 
int N;
int sign[5], num[13];
int min_cal = 1e9, max_cal = -1e9;
 
void findCal(int n, int cal) {
    if (n >= N - 1) {
        if (min_cal > cal) {
            min_cal = cal;
        }
        if (max_cal < cal) {
            max_cal = cal;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (n == 0) cal = num[0];
        if (sign[i] == 0) continue;
        switch (i)
        {
        case 0:
            sign[i]--;
            findCal(n + 1, cal + num[n + 1]);
            sign[i]++;
            break;
        case 1:
            sign[i]--;
            findCal(n + 1, cal - num[n + 1]);
            sign[i]++;
            break;
        case 2:
            sign[i]--;
            findCal(n + 1, cal * num[n + 1]);
            sign[i]++;
            break;
        case 3:
            sign[i]--;
            findCal(n + 1, cal / num[n + 1]);
            sign[i]++;
            break;
        default:
            break;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        // 초기화
        min_cal = 1e9, max_cal = -1e9;
         
        // 입력
        cin >> N;
        int n = 0;
        for (int i = 0; i < 4; i++) {
            cin >> sign[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> num[i];
        }
 
        // 숫자 만들기
        findCal(0, 0);
         
        // 출력
        cout << "#" << t << " " << max_cal - min_cal << "\n";
    }
    return 0;
}
