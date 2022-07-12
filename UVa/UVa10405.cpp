#include <bits/stdc++.h>
using namespace std;

int LCS(string a, string b){
    
    int lenA = a.size();
    int lenB = b.size();    
    int dp[lenA + 1][lenB + 1];

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= lenA; i++){
        for(int j = 1; j <= lenB; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[lenA][lenB];
}

int main(){

    string a, b;

    while(getline(cin, a)){
        getline(cin, b);
        cout << LCS(a, b) << endl;
    }

    return 0;
}