#include <bits/stdc++.h>
using namespace std;

int N;
int dpA[10001];
int dpB[10001];

void LIS(int *arr, int *dp){
    
    vector<int> v;
    
    for (int i = 0; i < N; i++){
        if (v.empty() || v.back() < arr[i]) {
            v.emplace_back(arr[i]);
        }
        else{
            *lower_bound(v.begin(), v.end(), arr[i]) = arr[i];
        }

        dp[i] = v.size() - 1;
    }
}

int main(){

    while(cin >> N){

        int a[N], b[N];

        memset(dpA, 0, sizeof(dpA));
        memset(dpB, 0, sizeof(dpB));

        for(int i = 0; i < N; i++){
            cin >> a[i];
            b[N - 1 - i] = a[i];
        }

        LIS(a, dpA);
        LIS(b, dpB); // LDS

        int MAX = 0;

        for(int i = 0; i < N; i++){
            cout << " " << dpA[i];
        }
        cout << endl;

        for(int i = N - 1; i >= 0; i--){
            cout << " " << dpB[i];
        }
        cout << endl;

        for(int i = 0; i < N; i++){
            MAX = max(MAX, min(dpA[i], dpB[N - 1 - i]));
        }

        cout << MAX * 2 + 1 << endl;
    }

    return 0;
}