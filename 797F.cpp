#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int P[n];
        for(int i = 0; i < n; i++){
            cin >> P[i];
            P[i]--;    
        }

        bool used[n] = {0};
        ll ans = 1;
        for(int i = 0; i < n; i++){
            if(used[i]){continue;}
            //for (auto x : used){cout << x << "*";}
            //cout << "\n";
            string t;
            int v = i;
            while(!used[v]){
                //cout << v << "&";
                t += s[v];
                used[v] = 1; 
                v = P[v];
            }
            //cout << "\n";
            int c = t.size();
            for(int k = 1; k <= c/2; k++){
                if(c%k == 0){
                    bool good = true;
                    for(int j = 0; j < c-k && good; j++){
                        if(t[j] != t[j + k]){
                            good = false;
                        }
                    }
                    if(good){
                        c = k;
                        break;
                    }
                }
            }
            //cout << c << "#";
            ans = lcm(ans, c);
        }
        cout << ans << "\n";
    }
    return 0;
}