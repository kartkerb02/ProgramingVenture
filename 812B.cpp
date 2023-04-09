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
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int p = 0, q = 0;
        for(int i = 0; i < n; i++){
            if(a[i] < a[p]) p = i;
            if(a[i] > a[q]) q = i;
        }
        bool q1 = 1, q2 = 1, q3 = 1, q4 = 1;
        // for(int i = p-1; i > 0; i--){
        //     if(a[i] > a[i-1]) q1 = 0;
        // }
        // for(int i = p+1; i < n-1; i++){
        //     if(a[i] > a[i+1]) q2 = 0;
        // }
        for(int i = q-1; i > 0; i--){
            if(a[i] < a[i-1]) q3 = 0;
        }
        for(int i = q+1; i < n-1; i++){
            if(a[i] < a[i+1]) q4 = 0;
        }
        // (q1 && q2) || 
        cout << (((q3 && q4)) ? "YES\n" : "NO\n");
        t--;
    }
    return 0;
}