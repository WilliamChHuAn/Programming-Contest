#include <bits/stdc++.h>
using namespace std;

#define lowbit(k) (k & -k)

int N;
int X;
int P[100001];

void add(int X, int val){
    for(; X <= N; X += lowbit(X)){
        P[X] += val;
    }
}

int sum(int X){

    int result = 0;

    for(; X >= 1; X -= lowbit(X)){
        result += P[X];
    }

    return result;
}

int main(){

    int ans;

    while(cin >> N && N){

        ans = 0;
        memset(P, 0, sizeof(P));

        for(int i = 0; i < N; i++){
            cin >> X;
            ans += i - sum(X);
            add(X, 1);
        }

        if(ans % 2){
            cout << "Marcelo\n";
        }
        else{
            cout << "Carlos\n";
        }
    }

    return 0;
}