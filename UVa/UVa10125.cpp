#include <bits/stdc++.h>
using namespace std;

int main(){

    int S;

    while(cin >> S && S){

        int n;
        vector<int> v;

        for(int i = 0; i < S; i++){
            cin >> n;
            v.emplace_back(n);
        }

        sort(v.begin(), v.end());

        int dif = 0;
        bool flag = true;
        map<int, pair<int, int>> mp;

        // [a + b] = d - c
        for(int a = 0; a < S; a++){
            for(int b = a + 1; b < S; b++){
                mp[v[a] + v[b]] = make_pair(v[a], v[b]);
            }
        }

        // a + b = [d - c]
        for(int d = S - 1; flag && d >= 0; d--){
            for(int c = 0; c < S; c++){
                if(c != d){

                    dif = v[d] - v[c];

                    if(mp.count(dif) != 0 && mp[dif].first != v[c] && mp[dif].second != v[c]){
                        cout << v[d] << endl;
                        flag = false;
                        break;
                    }
                }
            }
        }

        if(flag){
            cout << "no solution\n";
        }
    }

    return 0;
}