#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;

    cin >> N;

    int A;
    long long int B[N];

    cin >> A;
    B[0] = A;

    for(int i = 1; i < N; i++){
        cin >> A;
        B[i] = A + B[i - 1];
    }

    cout << B[0];

    for(int i = 1; i < N; i++){
        cout << " " << B[i];
    }

    cout << endl;

    return 0;
}