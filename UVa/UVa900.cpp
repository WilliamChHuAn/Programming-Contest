#include <bits/stdc++.h>
using namespace std;

long long int dp[51];

void init(){
    
    dp[0] = dp[1] = 1;

    for(int i = 2; i <= 50; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

int main(){

    init();

    int length;

    while(cin >> length && length){
        cout << dp[length] << endl;
    }

    return 0;
}