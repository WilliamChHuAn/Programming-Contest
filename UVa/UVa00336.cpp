#include <bits/stdc++.h>
using namespace std;

int NC;
int N, C;
int start;      // starting node number
int TTL;        // initial TTL field
int reachable;  // the number of reachable nodes
map<int, vector<int>> G;

void BFS(){

    int node;
    queue<int> q;
    map<int, int> dis;

    reachable = 1;  // starting node reachable
    dis[start] = 0; // distance between starting node to starting node = 0
    q.emplace(start);

    while(!q.empty()){

        node = q.front();
        q.pop();

        for(auto i: G[node]){
            if(dis.count(i) == 0){  // not visited
                
                dis[i] = dis[node] + 1;

                if(dis[i] <= TTL){
                    q.push(i);
                    reachable++;
                }
            }
        }
    }
}

int main(){

    int t = 1;

    while(cin >> NC && NC){

        G.clear();

        for(int i = 0; i < NC; i++){
            cin >> N >> C;
            G[N].emplace_back(C);
            G[C].emplace_back(N);
        }

        while(cin >> start >> TTL && (start || TTL)){
            if(G.count(start)){ // avoid query node not in the graph
                BFS();
                cout << "Case " << t++ << ": " << G.size() - reachable << " nodes not reachable from node " << start << " with TTL = " << TTL << ".\n";
            }
            else{
                cout << "Case " << t++ << ": " << G.size() << " nodes not reachable from node " << start << " with TTL = " << TTL << ".\n";
            }
        }
    }

    return 0;
}