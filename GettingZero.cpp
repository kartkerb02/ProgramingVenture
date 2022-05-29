#include<bits/stdc++.h>
using namespace std;

const int N = 32768;
//int dp[N + 1];

int power2(int x){
    int out = 0;
    while(x%2 == 0){
        x/=2;
        out++;
    }
    return out;
}
int solve(int num){
    int curr = power2(num);
    int mx = 0;
    for(int i = 1; i <= 15; i++){
        mx = max(mx, power2(num+i) - curr - i);
    }
    return 15 - curr - mx;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, num;
    cin >> n;

    while(n >0){
        cin >> num;
        cout << solve(num) << " ";
        n--;
    }
    return 0;
}

// int rec(int x){
//     // if(x >= N || x < 0){
//     //     return INT_MAX;
//     // }
//     //cout << x << endl;
//     if(x == 0){
//         return 0;
//     }
//     if(dp[x] != -1){
//         return dp[x];
//     }
//     return dp[x] = 1+ min(rec((x+1)%N), rec((x*2)%N));
// }
// int main(){
//     memset(dp, -1, sizeof(dp));
//     dp[0] = 0;
//     dp[1] = 15;
//     dp[2] = 14;
//     dp[4] = 13;
//     int n, num;
//     cin >> n;
//     while(n > 0){
//         cin >> num;
//         cout << rec(num%N) << endl;
//         n--;
//     }
//     return 0;
// }