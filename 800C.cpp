#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;   
    while(t){
        ll n;
        cin >> n;
        ll A[n+1] = {};
        ll sum[n+1] = {};
        ll currsum[n+1] = {0};
        bool now = true;
        bool done = false;
        for(ll i = 1; i <= n; i++){
            cin >> A[i]; 
            currsum[i] = currsum[i-1] + A[i];

            if(done && now && A[i] != 0){
                now = false;
                //cout << i;
            }
            if(!done && currsum[i] <= 0){
                done = true;
            }
            
        }

        sum[n] = A[n];
        for(ll i = n - 1; i >= 1; i--){
            sum[i] = sum[i+1] + A[i];
        }
        bool out = (sum[1] == 0 && sum[n] <= 0 && now);

        for(ll i = 1; i < n && out; i++){
            if(A[i] > 0 && A[i] + sum[i+1] > 0){
                out = false;
            }
        }
        cout << (out? "yes" : "no") << "\n";
        t--;
    }
    return 0;
}