#include <bits/stdc++.h>
using namespace std;

int M, N;
char S[1005][1005];
int dir[8][2] = { 1,  0,    // down
                  1,  1,    // down right
                  0,  1,    // right
                 -1,  1,    // up right
                 -1,  0,    // up
                 -1, -1,    // up left
                  0, -1,    // left
                  1, -1};   // down left

void drawMap(){
    cout << endl;
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cout << S[i][j];
        }
        cout << endl;
    }
}

void DFS(int x, int y){

    S[x][y] = '*';

    for(int i = 0; i < 8; i++){
        if(S[x + dir[i][0]][y + dir[i][1]] == '@'){
            DFS(x + dir[i][0], y + dir[i][1]);
        }
    }
}

int main(){

    cin >> M >> N;

    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cin >> S[i][j];
        }
    }

    int ans = 0;

    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            if(S[i][j] == '@'){
                ans++;
                // drawMap();
                DFS(i, j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}