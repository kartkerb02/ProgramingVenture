#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll q, type, a, b, n;
        cin >> q;
        ll hmin = 1, hmax = 1e18; // h \in [hmin, hmax]

        for(ll i = 0; i < q; i++){
            cin >> type;
            if(type == 1){
                cin >> a >> b >> n;
                ll use = 1;
                
                ll hmx = (n-1)*(a-b) + a;
                ll hmn = (n-2)*(a-b) + a + 1;
                if(n == 1) hmn = 1;

                if(hmx < hmin || hmn > hmax) use = 0;
                else{
                    hmax = min(hmax, hmx);
                    hmin = max(hmin, hmn);
                }
                cout << use << " ";
            }
            else{
                cin >> a >> b;
                ll n1 = (hmax - b + a - b - 1)/(a-b);
                ll n2 = (hmin - b - 1)/(a-b) + 1;

                if(a >= hmax) cout << 1 << " ";
                else if(n1 == n2){
                    cout << n2 << " ";
                }
                else cout << -1 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

