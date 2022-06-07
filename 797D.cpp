#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int cnt = 0;
        for(int  i = 0; i < k; i++){
            if(s[i] == 'B'){cnt++;}
        }
        int mx = cnt;
        for(int i = 1; i + k - 1 < n; i++){
            if(s[i-1] == 'B'){cnt--;}
            if(s[i+k-1] == 'B'){cnt++;}
            mx = max(mx, cnt);
        }
        cout << k - mx << "\n";
        t--;
    }
    return 0;
}