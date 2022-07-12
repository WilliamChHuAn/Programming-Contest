#include <bits/stdc++.h>
using namespace std;

int N;
char grid[105][105] = {0};
int dir[2][2] = { 1,  0,    // down
                  0,  1};   // right

void DFS(int x, int y){

    grid[x][y] = '.';

    for(int i = 0; i < 2; i++){
        if(grid[x + dir[i][0]][y + dir[i][1]] == 'x' || grid[x + dir[i][0]][y + dir[i][1]] == '@'){
            DFS(x + dir[i][0], y + dir[i][1]);
        }
    }
}

int main(){

    int T;
    int ans = 0;

    cin >> T;

    for(int t = 1; t <= T; t++){
        
        memset(grid, '.', sizeof(grid));

        cin >> N;

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                cin >> grid[i][j];
            }
        }

        ans = 0;

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(grid[i][j] == 'x'){
                    ans++;
                    DFS(i, j);
                }
            }
        }

        cout << "Case " << t << ": " << ans << endl;
    }

    return 0;
}