#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool sortbyfirstdec(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    return (a.first > b.first);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t > 0){
        ll n, k, sum = 0, temp;
        cin >> n >> k;

        ll save[n+1] = {};
        for(ll i = 1; i <= n; i++){
            cin >> temp;
            sum += temp;
            save[i] = temp - n + i; 
        }
        sort(save + 1, save + n + 1, greater<ll>());
        // for(ll i = 1; i <= n; i++){
        //     cout << save[i] << " ";
        // }
        // cout << "#\n";
        for(ll i = 1; i <= k && (save[i] + i -1) >= 0 ; i++){
            sum -= (save[i] + i - 1);
        }
        cout << sum << "\n";
        t--;
    }
    return 0;
}