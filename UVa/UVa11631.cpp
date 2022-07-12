#include<bits/stdc++.h>
using namespace std;

struct Edge{

    int u, v, w;

    bool operator < (const Edge &rhs) const{
        return w < rhs.w;
    }
};

vector<Edge> G;
int parent[100001];
long long int total;
long long int lightCost;

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

void kruskal(){

    sort(G.begin(), G.end());

    for(auto i: G){
        if(unit(i.u, i.v)){
            lightCost += i.w;
        }
    }
}

int main(){

    int m;  // the number of junctions -> |v|
    int n;  // the number of roads     -> |e|
    int x, y, z;

    while(cin >> m >> n && m && n){

        G.clear();
        lightCost = total = 0;
        memset(parent, -1, sizeof(parent));

        for(int i = 0; i < n; i++){
            cin >> x >> y >> z;
            G.push_back({x, y, z});
            total += z;
        }

        kruskal();

        cout << total - lightCost << endl;
    }

    return 0;
}