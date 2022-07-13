#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    int A, B;
    int L, R;

    while(cin >> N && N){

        N = N + N;

        int x[N];
        int y[N];
        bool flag = false;

        for(int i = 0; i < N; i++){
            cin >> x[i] >> y[i];
        }

        for(int i = -500; i <= 500; i++){           // Ax
            for(int j = -500; j <= 500; j++){       // By

                L = R = 0;

                for(int k = 0; k < N; k++){         // point

                    if(i * x[k] + j * y[k] == 0){   // point on line
                        break;
                    }

                    if(i * x[k] + j * y[k] > 0){
                        R++;
                    }
                    else{
                        L++;
                    }
                }

                if(L == R && L + R == N){
                    A = i;
                    B = j;
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }

        cout << A << " " << B << "\n";
    }

    return 0;
}