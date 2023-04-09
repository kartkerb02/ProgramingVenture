#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n, x;
        cin >> n >> x;
        vector<int> A(n);
        for(int i =0; i < n; i++) cin >> A[i];
        int l = A[0], h = A[0], cnt = 0;
        for(int i = 0; i < n; i++){
            l = min(l, A[i]);
            h = max(h, A[i]);
            if(h-l > 2*x){
                cnt++;
                l = A[i];
                h = A[i];
            }
        }
        cout << cnt << "\n";
        t--;
    }
    return 0;
}