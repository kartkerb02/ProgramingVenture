#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n, q;
        cin >> n >> q;
        vector<int> a(n), h(n, -1), nge(n, -1);
        for(int i = 0; i < n; i++) cin >> a[i];
        int cm = a[0];
        for(int i = 1; i < n; i++){
            if(a[i] < cm) h[i] = 0;
            cm = max(a[i], cm);
        }
        stack<int> s;
        s.push(0);
        for(int i = 1; i < n; i++){
            if(!s.empty()){
                while(!s.empty() && a[s.top()] < a[i]){
                    nge[s.top()] = i;
                    s.pop();
                }
            }
            s.push(i);
        }
        for(int i = 0; i < q; i++){
            int j, k;
            cin >> j >> k;
            j--;
            int res = -1;
            if(h[j] == 0 || j > k + 1){
                res = 0;
            }
            else if(h[j] != 0 && a[j] == n){
                res =  k - j + 1;
                if(j == 0) res--;
            }
            else if(h[j] != 0){
                if(k >= nge[j] - 1){
                    res = nge[j] - j;
                }
                else{
                    res = k - j + 1;
                }
                if(j == 0) res--;

            }
            cout << res << "\n";
        }

        t--;
    }
    return 0;
}