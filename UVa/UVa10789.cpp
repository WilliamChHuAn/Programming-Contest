#include <bits/stdc++.h>
using namespace std;

const int maxLen = 2001;    // max length of string
const int maxASCII = 128;
bool isPrime[maxLen] = {false};

void seivePrime(){

    isPrime[0] = isPrime[1] = true;

    for(int i = 2; i < sqrt(maxLen); i++){
        if(isPrime[i] == false){
            for(int j = i * i; j <= maxLen; j = j + i){
                isPrime[j] = true;
            }
        }
    }

    // for(int i = 0; i < maxLen; i++){
    //     if(isPrime[i] == false){
    //         cout << i << "\n";
    //     }
    // }
}

int main(){

    seivePrime();

    int T;

    cin >> T;

    for(int t = 1; t <= T; t++){

        string str;
        int cntAlpha[maxASCII] = {0};

        cin >> str;

        for(int i = 0; i < str.size(); i++){
            cntAlpha[str[i]]++;
        }

        bool flag = true;

        cout << "Case " << t << ": ";

        for(int i = 0; i < maxASCII; i++){
            if(isPrime[cntAlpha[i]] == false){  // isPrime[i] == false -> i is prime
                cout << char(i);
                flag = false;
            }
        }

        if(flag){
            cout << "empty\n";
        }
        else{
            cout << "\n";
        }
    }

    return 0;
}