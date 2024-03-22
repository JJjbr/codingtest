#include<iostream>
#include<vector>
using namespace std;

vector<int> scores[4][3001];
int people[4][100002];

int main(int argc, char** argv)
{
    int N;
    cin >> N;
    int score;
    for(int i=0; i<3; i++){
        for(int j=0; j<N; j++){
            cin >> score;
            scores[i][score].push_back(j);
            people[0][j] += score;
        }
    }
    for(int i=0; i<N; i++){
        scores[3][people[0][i]].push_back(i);
        people[0][i] = 0;
    }

    int rank = 1;
    for(int i=0; i<4; i++){
        rank = 1;
        for(int j=3000; j>=0; j--){
            if(scores[i][j].size() > 0){
                for(int k=0; k<scores[i][j].size(); k++){
                    people[i][scores[i][j][k]] = rank;
                }
                rank += scores[i][j].size();
            }
        }
    }
    
    for(int i=0; i<4; i++){
        for(int j=0; j<N; j++){
            cout << people[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
