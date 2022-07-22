#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n, m;
        cin >> n >> m;
        unsigned long long ans = m*(m-1)/2;
        unsigned long long ans2 = n*(n+1)/2;
        cout << ans2*m + ans << "\n";
        t--;
    }
    return 0;
}