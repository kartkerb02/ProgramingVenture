#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;   
    while(t){
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> C(n, vector<ll>(m));
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++) cin >> C[i][j];
        }
        vector<ll> D(n, 0);
        ll mx = INT_MIN, ind = 0;
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                D[i] += j*C[i][j];
            }
            if(D[i] > mx){
                mx = D[i];
                ind = i;
            }
        }
        ll mn = min(D[0], D.back());

        cout << ind+1 << " " << mx-mn << "\n";
        t--;
    }
    return 0;
}