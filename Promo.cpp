#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    int p[n+1];
    for(int i = 1; i <= n ; i++){cin >> p[i];}

    sort(p+1, p+n+1, greater<int>());
    ll sum[n+1] = {};
    for(int i = 1; i<=n; i++){
        sum[i] = sum[i-1] + p[i];
    }
    for(int i = 0; i< q; i++){
        int x, y;
        cin >> x >> y;
        
        cout << sum[x] - sum[x-y] << "\n";
    }
    return 0;
}