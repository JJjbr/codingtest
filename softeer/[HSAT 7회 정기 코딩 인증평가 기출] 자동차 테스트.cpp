#include<iostream>
#include<algorithm>
using namespace std;

int n;
int car[50002];

void bs(int s, int e, int target){
    int mid;
    while(s <= e){
        mid = (s + e) / 2;

        if(car[mid] == target){
            cout << mid * (n - mid - 1) << "\n";
            return;
        }

        if(car[mid] < target){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    cout << 0 << "\n";
}

int main(int argc, char** argv)
{
    int q, m;
    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> car[i];
    }
    sort(car, car + n);
    for(int i=0; i<q; i++){
        cin >> m;
        bs(0, n - 1, m);
    }
    return 0;
}
