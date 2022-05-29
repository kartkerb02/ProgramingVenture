#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t > 0){
        int n, sum = 0, avg;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++){
            cin >> A[i];
            sum += A[i];
        }
        bool out = true;
        if(sum%n == 0){
            avg = sum/n;
            out = false;
            for(int i = 0; i < n && ~out; i++){
                if(A[i] == avg){
                    out = true;
                }
            }
        }
        else{
            out = false;
        }
        cout << (out? "yes" : "no") << "\n";
        t--;
    }
}