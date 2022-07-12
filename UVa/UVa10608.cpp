#include<bits/stdc++.h>
using namespace std;

int parent[500001];

int find(int x){
    if(parent[x] < 0){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unit(int a, int b){

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
    }
}

int main(){

    int t;
    int N, M;
    int A, B;

    cin >> t;

    while(t--){

        cin >> N >> M;

        memset(parent, -1, sizeof(parent));

        for(int i = 0; i < M; i++){
            cin >> A >> B;
            unit(A, B);
        }

        int MAX = 0;

        for(int i = 1; i <= N; i++){
            MAX = max(MAX, -parent[i]);
        }

        cout << MAX << endl;
    }

    return 0;
}