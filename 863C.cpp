#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> B(n-1), A(n);
        for(ll i = 0; i < n-1; i++) cin >> B[i];

        A[0] = B[0];
        A[n-1] = B[n-2];
        ll i = 0;
        for(i = 0; i < n-2; i++){
            if(B[i] < B[i+1]){
                A[i+1] = B[i];
                A[i+2] = B[i+1];
                i++;
            }
            else{
                A[i+1] = B[i+1]; 
            }
        }
        
        for(ll j = 0; j < n; j++){
            cout << A[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}