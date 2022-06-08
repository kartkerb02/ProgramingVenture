#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t > 0){
        ll n, k, sum = 0;
        cin >> n >> k;
        ll A[n];
        for(int i = 0; i < n; i++){cin >> A[i]; sum += A[i];}

        ll ans = 0;
        if(n == 1){
            ans = A[0] + k - 1;
        }
        else if(k > n){
            int a = k%(n-1);
            ans = n*(n+ 2*a -3)/2 + n*(n-1)*(k/(n-1) - 1) + sum;
            // = 0 + 1 + 2 + ... a-1
            // + 2 + 4 + 6 + ... + 2(a-1)
            // + (2*a-1) + (2*a) + .... (n-a) terms
            // + (k/(n-1) - 1)*n*(n-1)
            // + sum
        }
        else{
            sum =  0;
            for(int i = 0; i < k; i++){
                sum += A[i];
            }
            ll mxsum = sum;
            for(int i = 0; i + k < n; i++){
                sum += A[i+k] - A[i];
                mxsum = max(mxsum, sum);
            }
            ans = mxsum + k*(k-1)/2;
        }
        cout << ans << "\n";
        t--;
    }
    return 0;
}