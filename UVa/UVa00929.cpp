#include <bits/stdc++.h>
using namespace std;

int N;  // the number of rows
int M;  // the number of columns
int dis[1000][1000];
int maze[1000][1000];
int dir[4][2] = { 1,  0,    // down
                  0,  1,    // right
                 -1,  0,    // up
                  0, -1};   // left

struct Cell{

    int x, y, cost;

    bool operator < (const Cell &rhs) const {
        return cost > rhs.cost;
    }
};

void Dijkstra(int x, int y){

    int nextX, nextY;
    priority_queue<Cell> pq;

    dis[x][y] = maze[x][y];
    pq.push({x, y, dis[x][y]});

    while(!pq.empty()){

        Cell now = pq.top();
        pq.pop();

        for(int i = 0; i < 4; i++){
            
            nextX = now.x + dir[i][0];
            nextY = now.y + dir[i][1];
            
            if(nextX < 1 || nextX > N || nextY < 1 || nextY > M){
                continue;
            }

            if(dis[nextX][nextY] > now.cost + maze[nextX][nextY]){
                dis[nextX][nextY] = now.cost + maze[nextX][nextY];
                pq.push({nextX, nextY, dis[nextX][nextY]});
            }
        }
    }
}

int main(){

    int T;

    cin >> T;

    while(T--){

        cin >> N >> M;

        memset(dis, 0x3f, sizeof(dis));
        memset(maze, 0x3f, sizeof(maze));

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                cin >> maze[i][j];
            }
        }

        Dijkstra(1, 1);

        cout << dis[N][M] << endl;
    }

    return 0;
}