#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll max(ll a, ll b){
    return (a > b ? a : b);
}
ll solve(vector<vector<int>>& A, ll m){

    vector<vector<int>> v1(2, vector<int>(m, 0));
    for(ll i = 1; i < m; i++) v1[0][i] = max(v1[0][i-1], A[0][i]) + 1;
    v1[1][m-1] = max(v1[0][m-1], A[1][m-1]) + 1;
    for(ll i = m-2; i >= 0; i--) v1[1][i] = max(v1[1][i+1], A[1][i]) + 1;

    vector<vector<int>> v2(2, vector<int>(m, 0));
    for(ll i = 1; i < m; i++) v2[1][i] = max(v2[1][i-1], A[1][i]) + 1;
    v2[0][m-1] = max(v2[1][m-1], A[0][m-1]) + 1;
    for(ll i = m-2; i >= 0; i--) v2[0][i] = max(v2[0][i+1], A[0][i]) + 1;

    ll x = 1, y = 0;
    ll curr = A[1][0] + 1;
    ll ans = v1[1][0] - v1[0][0];
    for(ll i = 0; i < m/2; i++){
        ans = min(ans, curr + v2[x-1][y+1] - v2[x][y]);

        y++;
        curr = max(curr, A[x][y]) + 1;
        x--;
        curr = max(curr, A[x][y]) + 1;

        ans = min(ans, curr + v1[x+1][y] - v1[x][y]);
        y++;
        if(y < m)curr = max(curr, A[x][y]) + 1;
    }
    if(m&1){
        curr = max(curr, A[x][y]) + 1;
        ans = min(ans, curr + v1[1][m-1] - v1[0][m-1]);
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;   
    while(t){
        ll m;
        cin >> m;
        vector<vector<int>> A(2, vector<int>(m, 0));
        for(ll i = 0; i < 2; i++){
            for(ll j = 0; j < m; j++){
                cin >> A[i][j];
            }
        }
        cout << solve(A, m) << "\n";
        t--;
    }
    return 0;
}