#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll n, q, t, j, x;
    cin >> n >> q;
    ll A[n+1];
    ll last_two_changedby[n+1] = {};
    ll sum = 0;
    ll last_two_ = -1, last_two_val = 0;

    for(ll i = 1; i <= n; i++){
        cin >> A[i];
        sum += A[i];
    }
    
    for(ll i = 0; i < q; i++){
        cin >> t;
        if(t == 1){
            cin >> j >> x;
            //cout << last_two_changedby[j] << "_" <<  last_two_ << "\n";

            if(last_two_changedby[j] > last_two_){
                sum += x - A[j];
            }
            else{
                sum += x - last_two_val;
            }
            last_two_changedby[j] = i;
            A[j] = x;
        }
        else if(t == 2){
            cin >> x;
            sum = n*x;
            last_two_ = i;
            last_two_val = x;
        }
        cout << sum << "\n";
    }
    return 0;
}