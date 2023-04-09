#include <bits/stdc++.h>
using namespace std;

#define ll long long

//binary search twice making overall TC O(log^2(N))

// computes numbers in the sequence 1, 2, 3, 5, 6, 7, 8 ... (having no 4 digit)
// which are strictly (< n)

ll f(ll n){
    string s = to_string(n);
    ll sz = s.size();

    ll out = 0;

    for(int i = 1; i <= sz-1; i++) out += pow(9,i-1)*8; //numbers with sie smaller than sz

    for(int i = sz; i > 0; i--){
        // fix MSD and rest number is free
        int free = (s[0]-'0');
        if((s[0]-'0') > 4) free--;
        if(sz == i) free--; //can't have 0 as MSD

        out += free*pow(9, i-1);
        s.erase(0, 1); // pop front
    }
    return out;
}
ll has4(ll n, bool lo){
    // if the given number has 4, compute the first digit larger (smaller if lo false) than n which doesn't has digit 4 in it.
    string ret = to_string(n);
    bool flag = 0;
    for(int i = 0; i < ret.size(); i++){
        if(flag) ret[i] = (lo? '0' : '9');
        if(ret[i] == '4') {ret[i] = (lo ? '5' : '3'); flag = 1;}
    }
    return stoll(ret);
}
ll fval(ll k){
    // binary search
    ll ans;
    ll lo = 0, hi = pow(10, 14), mid;
    while(lo < hi){
        lo = has4(lo, true);
        hi = has4(hi, false);
        
        mid = lo + (hi - lo)/2;
        mid = has4(mid, false);

        ll tmp = f(mid);
        if(tmp == k-1) return mid;
        else if(tmp > k-1) hi = mid-1;
        else lo = mid + 1;
    }

    return hi;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << fval(n) << "\n";
    }
    return 0;
}