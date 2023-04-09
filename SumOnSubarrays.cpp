#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> out;
        int ind = 0;

            while(ind < n){
                if(k == 0){
                    out.push_back(-1);
                    ind++;
                }
                else if(k >= n-ind){
                    out.push_back(1000);
                    k -= (n-ind);
                    ind++;
                }
                else{
                    out.push_back(k);
                    ind++;
                    for(int i = 0; i < k-1; i++){
                        out.push_back(-1);
                        ind++;
                    }
                    while(ind < n){
                        out.push_back(-2);
                        ind++;
                    }
                }
                
            }
        
        for(auto x : out) cout << x << " ";
        cout << "\n";
    }
    return 0;
}