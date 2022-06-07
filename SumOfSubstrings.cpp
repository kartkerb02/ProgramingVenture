#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        long long int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        long long int mn = INT_MAX, mx = INT_MIN, cnt = 0, out = 0;

        for(long long int i = 0; i < n; i++){
            if(s[i] == '1'){
                cnt++;
                mn = min(mn, i);
                mx = max(mx, i);
            }        
        }
        if(n - mx - 1 <= k){
            k -= n - mx - 1;
            out += 1;
            cnt --;
        }
        if(mn <= k && !(mn == mx && out != 0)){
            k -= mn;
            out += 10;
            cnt --;
        }
        out += cnt*11;

        cout << out << "\n";
        t--;
    }
}