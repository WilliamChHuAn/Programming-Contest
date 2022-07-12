#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    int W;  // the number of East-West streets
    int N;  // the number of North-South streets
    int X;  // the number of unsafe
    int pos;

    cin >> t;

    while(t--){

        cin >> W >> N;

        int mp[W + 1][N + 1];
        bool unsafe[W + 1][N + 1];

        memset(mp, 0, sizeof(mp));
        memset(unsafe, false, sizeof(unsafe));

        for(int i = 1; i <= W; i++){
            cin >> i >> X;
            while(X--){
                cin >> pos;
                unsafe[i][pos] = true;
            }
        }

        mp[0][1] = 1;

        for(int i = 1; i <= W; i++){
            for(int j = 1; j <= N; j++){
                if(!unsafe[i][j]){
                    mp[i][j] = mp[i - 1][j] + mp[i][j - 1];
                }
            }
        }

        cout << mp[W][N] << "\n";
    }

    return 0;
}