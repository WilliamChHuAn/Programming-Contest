#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    string str;

    cin >> n;

    while(n--){

        cin >> str;
        sort(str.begin(), str.end());

        do{
            cout << str << "\n";
        }while(next_permutation(str.begin(), str.end()));
    }

    return 0;
}