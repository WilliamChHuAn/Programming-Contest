#include <bits/stdc++.h>
using namespace std;

int n;  // number of integer
int a[1000001];
int buf[1000001];

long long Inversion(int left, int right){

    if (right - left <= 1){ // finish split
        return 0;
    }
    
    int middle = (right + left) / 2;
    long long ans = Inversion(left, middle) + Inversion(middle, right);
    int i = left, j = middle, k = left;

    while (i < middle || j < right){
        if (i >= middle){
            buf[k] = a[j++];
        }
        else if (j >= right){
            buf[k] = a[i++];
        }
        else{
            if (a[i] <= a[j]){
                buf[k] = a[i++];
            }
            else{
                buf[k] = a[j++];
                ans += middle - i;
            }
        }
        k++;
    }
    
    for (int k = left; k < right; k++){
        a[k] = buf[k];
    }

    return ans;
}

int main(){

    while(cin >> n && n){

        memset(a, 0, sizeof(a));
        memset(buf, 0, sizeof(buf));

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        cout << Inversion(0, n) << endl;
    }

    return 0;
}