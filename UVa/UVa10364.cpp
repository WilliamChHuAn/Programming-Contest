#include <bits/stdc++.h>
using namespace std;

int N;  // the number of test cases
int M;  // the number of sticks
int stick[20];  // length of stick[i]
bool used[20];  // stick[i] is used or not
int sumLength;
int sideLength;

bool DFS(int finishSide, int chooseSideLength, int choose){

    if(finishSide == 3){
        return true;
    }

    if(chooseSideLength == sideLength){
        if(DFS(finishSide + 1, 0, 0)){
            return true;
        }
    }

    for(int i = choose; i < M; i++){
        if(!used[i] && stick[i] + chooseSideLength <= sideLength){
            
            used[i] = true;
            
            if(DFS(finishSide, chooseSideLength + stick[i], i + 1)){
                return true;
            }

            used[i] = false;
        }
    }

    return false;
}

int main(){

    cin >> N;

    while(N--){

        cin >> M;

        sumLength = sideLength = 0;
        memset(stick, 0, sizeof(stick));
        memset(used, false, sizeof(used));

        for(int i = 0; i < M; i++){
            cin >> stick[i];
            sumLength += stick[i];
        }

        if(sumLength % 4){
            cout << "no\n";
            continue;
        }

        sideLength = sumLength / 4;

        sort(stick, stick + M, greater<int>());

        if(stick[0] > sideLength){
            cout << "no\n";
            continue;
        }

        if(DFS(0, 0, 0)){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }

    return 0;
}