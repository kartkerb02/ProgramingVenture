#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n, x, y; cin >> n >> x >> y;

        vector<ll> f(n+1, 1);
        for(int i = 2; i <= n; i++) f[i] = f[i-1] + f[i-2];

        bool out = true;
        for(int i = n; i > 0; i--){
            if(y > f[i]){
                y -= f[i];
            }
            else if(y <= f[i-1]){

            }
            else{
                out = false;
                break;
            }
            swap(x, y);
        }
        cout << (out ? "yes\n" : "no\n");
    }
    return 0;
}