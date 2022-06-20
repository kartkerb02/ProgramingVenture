#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NUM_PIGS = 105;
const int NUM_ROUNDS = 105;

int dp[NUM_PIGS][NUM_ROUNDS] = {};

int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
 
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

int dfs(int pigs, int rounds){
    if(dp[pigs][rounds] != 0){
        return dp[pigs][rounds];
    }
    else if(rounds == 0 || pigs == 0){
        return dp[pigs][rounds] = 1;
    }
    else if (rounds == 1){
        return dp[pigs][rounds] = pow(2, pigs);
    }
    int wt = 1;
    int out = 0;
    for(int i = 0; i < pigs + 1; i++){
        out += nCr(pigs, i)*dfs(pigs - i, rounds - 1);
    }

    return dp[pigs][rounds] = out;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, 0, sizeof(dp));
    
    cout << dfs(5, 4);
    cout << "\n";

    for(int i = 0; i < 10; i++){
        for(int  j = 0; j < 10; j++){
            cout << dfs(i,j) << " ";
        }
        cout << "\n";
    }
    
    return 0;
}