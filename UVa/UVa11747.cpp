#include<bits/stdc++.h>
using namespace std;

struct Edge{

    int u, v, w;

    bool operator < (const Edge &rhs) const{
        return w < rhs.w;
    }
};

vector<int> H;
vector<Edge> G;
int parent[1001];

int find(int x){
    if(parent[x] < 0){
        return x;
    }
    return parent[x] = find(parent[x]);
}

bool unit(int a, int b){

    a = find(a);
    b = find(b);

    if(a != b){
        if(parent[a] < parent[b]){
            parent[a] += parent[b];
            parent[b] = a;
        }
        else{
            parent[b] += parent[a];
            parent[a] = b;
        }
        return true;
    }

    return false;
}

bool kruskal(){

    sort(G.begin(), G.end());

    for(auto i: G){
        if(!unit(i.u, i.v)){
            H.emplace_back(i.w);
        }
    }

    if(H.empty()){
        return true;
    }

    return false;
}

int main(){

    int n;  // the number of nodes
    int m;  // the number of edges
    int u, v, w;

    while(cin >> n >> m && (n || m)){

        H.clear();
        G.clear();
        memset(parent, -1, sizeof(parent));

        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            G.push_back({u, v, w});
        }

        if(kruskal()){
            cout << "forest\n";
        }
        else{

            cout << H[0];

            for(int i = 1; i < H.size(); i++){
                cout << " " << H[i];
            }

            cout << "\n";
        }
    }

    return 0;
}