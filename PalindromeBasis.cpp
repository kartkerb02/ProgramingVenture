#include<bits/stdc++.h> 
using namespace std;

const int mod = 1e9 + 7;
const int N = 4e4 + 1;

vector<int> weights;


bool ispalin(int x){
    string s1 = to_string(x);
    string s2 = to_string(x);
    reverse(s1.begin(), s1.end());
    return (s1 == s2);
}

void process(){
    for(int i = 0; i < N; i++){
        if(ispalin(i)){
            weights.push_back(i);
        }
    }
}

int dp[500][N];

int rec(int level, int n_left){
    if(n_left == 0){
        return 1;
    }

    if(n_left < 0 || level == weights.size()){
        return 0;
    }

    if(dp[level][n_left] != -1){
        return dp[level][n_left];
    }
    
    int ans = rec(level+1, n_left) + rec(level, n_left - weights[level]);
    ans%= mod;
    return dp[level][n_left] = ans;
}


void solve(){
    int n;
    cin >> n;
    
    int ans = rec(0, n);
    cout << ans << "\n";
}

int main(){
    
    process();
    memset(dp, -1, sizeof(dp));

    int t = 5;
    while(t > 0){
        solve();
        t--;
    }
    return 0;
}