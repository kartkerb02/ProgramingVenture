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
        string s;
        cin >> s;

        ll ans = n;
        for(ll i = 0; i < n - 1; i++){
            if(s.substr(i, 2) == "01" || s.substr(i, 2) == "10"){
                ans += i + 1;
                //cout << i <<  " ";
            }
        }
        cout << ans << "\n";
        t--;
    }
    return 0;
}