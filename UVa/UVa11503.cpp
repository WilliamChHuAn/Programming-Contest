#include<bits/stdc++.h>
using namespace std;

int parent[100001];

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
    int F;

    cin >> t;

    while(t--){

        cin >> F;

        string A, B;
        map<string, int> mp;

        memset(parent, -1, sizeof(parent));

        for(int i = 1; F--;){

            cin >> A >> B;

            if(mp[A] == 0){
                mp[A] = i++;
            }
            if(mp[B] == 0){
                mp[B] = i++;
            }

            unit(mp[A], mp[B]);

            cout << -parent[find(mp[A])] << endl;
        }
    }

    return 0;
}