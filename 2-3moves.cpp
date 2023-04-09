#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int solve(int n){
    if(n == 1) return 2;
    int ans = n/3;
    if(n%3 != 0){
        ans++;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n;
        cin >> n;
        
        cout << solve(n) << "\n";
        t--;
    }
    return 0;
}