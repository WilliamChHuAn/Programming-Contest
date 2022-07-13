#include <bits/stdc++.h>
using namespace std;

int R, C;
int Time[1005][1005];
char maze[1005][1005];
int dir[8][2] = { 1,  0,    // down
                  0,  1,    // right
                 -1,  0,    // up
                  0, -1};   // left

struct pos{
    int x;
    int y;
    bool isJoe;
};

void drawMap(){
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cout << Time[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int BFS(){

    pos Joe;
    queue<pos> q;

    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            if(maze[i][j] == 'J'){
                Joe = {i, j, true};
            }
            if(maze[i][j] == 'F'){
                q.push({i, j, false}); // fire enter queue first because test case 2
            }
        }
    }

    pos p;
    q.push(Joe);    // Joe enter queue
    Time[Joe.x][Joe.y] = 0;

    while(!q.empty()){

        p = q.front();
        q.pop();

        if(p.isJoe && (p.x == 1 || p.y == 1 || p.x == R || p.y == C)){   // Joe on borders
            return Time[p.x][p.y] + 1;  // return the earliest time Joe can safely exit the maze
        }

        for(int i = 0; i < 4; i++){
            if(maze[p.x + dir[i][0]][p.y + dir[i][1]] == '.' && Time[p.x + dir[i][0]][p.y + dir[i][1]] == -1){    // a passable square and no fire
                Time[p.x + dir[i][0]][p.y + dir[i][1]] = Time[p.x][p.y] + 1;
                q.push({p.x + dir[i][0], p.y + dir[i][1], p.isJoe});
                // drawMap();
            }
        }
    }

    return -1;
}

int main(){

    int T;

    cin >> T;

    while(T--){

        cin >> R >> C;

        memset(Time, -1, sizeof(Time));
        memset(maze, 'x', sizeof(maze));

        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++){
                cin >> maze[i][j];
            }
        }

        // drawMap();

        int minutes = BFS();

        if(minutes == -1){
            cout << "IMPOSSIBLE\n";
        }
        else{
            cout << minutes << endl;
        }

    }

    return 0;
}