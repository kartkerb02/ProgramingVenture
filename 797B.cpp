#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n;
        cin >> n;
        long long int A[n] = {};
        long long int B[n] = {};
        long long int z = 0;

        long long int k = 38926742;
        for(int i =0; i < n; i++){cin >> A[i];}
        for(int i =0; i < n; i++){
            cin >> B[i];
            if(B[i] > 0){
                k = A[i] - B[i];
            }
        }
        bool out = true;


        if(k == 38926742){
            out = true;
        }
        else if(k < 0){
            out = false;
        }
        else{
            for(int i =0; i < n && out; i++){
                if(max(A[i] - k , z) != B[i]){
                    out = false;
                }
            }
        }
        cout << (out? "YES" : "NO") << "\n";
        t--;
    }
    return 0;
}