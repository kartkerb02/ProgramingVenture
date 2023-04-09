#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n;
        cin >> n;
        vector<int> A(n), B(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        for(int i = 0; i < n; i++) cin >> B[i];

        for(int i = 0; i < n; i++) B[i] -= A[i];
        int ans = 0;
        sort(B.begin(), B.end());
        int l = 0, r = n-1;
        while(l <= r){
            if(B[l] >= 0){
                ans += (r-l+1)/2;
                break;
            }
            else if(B[l] + B[r] < 0)l++;
            else if(B[l] + B[r] >= 0){
                ans ++;
                l++;
                r--;
            }
        }
        cout << ans << "\n";

        t--;
    }
    return 0;
}