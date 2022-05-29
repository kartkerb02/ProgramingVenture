#include<bits/stdc++.h>
using namespace std;

int modifyBit(int n, int p, int b)
{
    int mask = 1 << p;
    return ((n & ~mask) | (b << p));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k, curr;
    cin >> t;
    while(t > 0){
        cin >> n >> k;
        int A[31] = {};
        for(int i = 0; i < n; i++){
            cin >> curr;
            for(int j = 0; j < 31; j++){
                A[j] += curr & 1;
                curr = curr>>1;
            }
        }
        
        long int out = 0;
        for(int  i = 30; i >= 0 && k >=0; i--){
            if(A[i] == n){
                out = modifyBit(out, i, 1);
            }
            else if(n-A[i] > k){
                continue;
            }
            else{
                k -= n-A[i];
                A[i] = n;
                out = modifyBit(out, i, 1);
            }
        }
        // for(auto x: A){
        //     cout << x << " ";
        // }
        // cout << "#\n";
        cout << out << "\n";
        t--;
    }
}