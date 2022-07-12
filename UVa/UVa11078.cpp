#include <bits/stdc++.h>
using namespace std;

int main(){

    int T;
    int n;

    cin >> T;

    while(T--){

        cin >> n;

        int MAX = -1e9;
        int MAXd = -1e9;
        int score[n];

        for(int i = 0; i < n; i++){
            cin >> score[i];
        }

        MAX = score[0];

        for(int i = 1; i < n; i++){
            MAXd = max(MAXd, MAX - score[i]);
            MAX = max(MAX, score[i]);
        }

        cout << MAXd << endl;
    }

    return 0;
}