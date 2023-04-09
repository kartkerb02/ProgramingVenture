#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll max(ll a, ll b){
    return (a > b ? a : b);
}
ll min(ll a, ll b){
    return (a < b ? a : b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = -1;
        ll mx = max(a*d, b*c);
        ll mn = min(a*d, b*c); 
        if(mx == 0 ^ mn == 0) ans = 1;
        else if(a*d == b*c) ans = 0;
        else if (mx % mn == 0) ans = 1;
        else ans = 2;
        
        cout << ans << "\n";
        t--;
    }
    return 0;
}