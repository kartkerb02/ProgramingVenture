#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Merge(ll* arr, ll l, ll m, ll r){
    
    ll i = l;
    ll j = m+1;
    ll k = l;

    ll temp[r - l + 5];

    while(i <= m && j <= r){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= m){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= r){
        temp[k] = arr[j];
        j++;
        k++;
    }
    //extra work
    i = m; j = r;
    ll out = 0;
    while(i >= l && j > m){
        if(arr[i] <= arr[j]){
            j--;
        }
        else{
            out += j - m;
            i--;
        }
    }

    //final merging work
    for (ll p = l; p <= r; p++) {
        arr[p] = temp[p];
    }
    return out;
}

ll MergeSort(ll* arr, ll l, ll r){
    if(l < r){
        ll m = (r - l)/2 + l;
        ll out = 0;
        out += MergeSort(arr, l, m);
        out += MergeSort(arr, m + 1, r);

        out += Merge(arr, l, m, r);
        return out;
    }
    return 0;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;   
    while(t){
        ll n;
        cin >> n;
        ll B[n+5] = {};
        
        for(ll i = 1; i<= n; i++){cin >> B[i];}
        ll ans = MergeSort(B, 1, n);

        vector<ll> grp;
        ll sz = 1;
        for(ll i = 1; i<= n; i++){
            if(B[i] == B[i-1]){
                sz++;
            }
            else{
                if(sz != 1){
                    grp.push_back((sz*(sz-1))/2);
                    sz = 1;
                }
            }
        }
        if(sz != 0){
            grp.push_back((sz*(sz-1))/2);
            sz = 0;
        }
        for(ll i = 0; i <grp.size(); i++){
            ans += grp[i];
        }
        cout << ans << "\n";
        t--;
    }
    return 0;
}

// #include<iostream>
// #include <vector>
// using namespace std;
// int main() {
// int t; cin>>t;
// while(t--){
//     long long n,rez=0;
//     cin>>n;
//     vector<int> a(n),T(n+1);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     for(int i=n-1;i>=0;i--){
//         for(int x=a[i] ; x>0; x -= x&-x){
//             rez+=T[x];
//         }
//         for(int x=a[i]; x<=n; x+=x&-x){
//             T[x]+=1;
//         }
//     }
//     cout<<rez<<'\n';
//     }
//   return 0;
// }