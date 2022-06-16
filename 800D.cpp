#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e5 + 5;
vector<ll> children[N+1];
ll l[N], r[N];
ll ans;

ll dfs(ll x){
    ll sum = 0;
    for(ll v : children[x]){
        sum += dfs(v);
    }
    if(l[x] <= sum){
        return min(r[x], sum);
    }
    ans++;
    return r[x];
}

void solve(){
    ll n;
    cin >> n;
    ll p[n+1];
    for(ll i = 2; i <= n; i++){
        cin >> p[i];
        children[p[i]].push_back(i);
    }
    for(ll i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
    }
    dfs(1);
    cout << ans << "\n";
    ans = 0;
    for(ll i = 0; i < n; i++){
        children[i].clear();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;   
    while(t){
        solve();
        t--;
    }
    return 0;
}
