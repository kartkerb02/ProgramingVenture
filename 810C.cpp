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
        ll h[n];
        ll val[n] = {};
        for(ll i =0; i < n; i++) cin >> h[i];
        for(ll i = 1; i < n-1; i++){
            ll tmp = max(h[i-1], h[i+1]) - h[i];
            if(tmp >= 0) val[i] = tmp + 1;
        }
        ll ans1 = 0;
        for(ll i = 1; i < n-1; i+=2){
            ans1 += val[i];
        }
        ll curr = ans1;
        ll ans2 = ans1;
        if(n&1) cout << ans1 << "\n";
        else{
            for(ll i = n - 2; i > 0; i-=2){
                curr = curr + val[i] - val[i-1];
                ans2 = min(ans2, curr);
            }
            cout << min(ans1, ans2) << "\n";
        }
        t--;
    }
    return 0;
}