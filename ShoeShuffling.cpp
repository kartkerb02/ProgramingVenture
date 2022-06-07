#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        int S[n+1] = {};
        int T[n+1] = {};
        for(int i = 0; i < n; i++){cin >> S[i];}

        int count = 1;
        bool out = true;
        for(int i = 0; i < n && out; i++){
            if(S[i] != S[i+1]){
                if(count > 1){
                    T[i] = i - count + 2;
                    count = 1;
                }
                else{
                    out = false;
                }
            }
            else{
                count ++;
                T[i] = i+2;
            }
        }
        if(out){
            for(int i = 0; i < n; i++){cout << T[i] << " ";}
            cout << "\n";
        }
        else{
            cout << -1 << "\n";
        }
        t--;
    }

}