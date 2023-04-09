#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>> f(26);
        bool ulta = 0;
        
        int st = s[0] - 'a';
        int en = s[n-1] - 'a';

        if(en < st) {
            reverse(s.begin(), s.end());
            ulta = 1;
            int tmp = st;
            st = en;
            en = tmp;
        }
        

        for(int i = 0; i < n; i++) f[s[i]-'a'].push_back(i);

        vector<int> ans;
        int sum = 0;
        for(int i = st; i <= en; i++){
            sum += f[i].size();
            ans.insert(ans.end(), f[i].begin(), f[i].end());
        }
        if(ulta){
            for(int i = 0; i < ans.size(); i++) {
                // cout << "yes
                ans[i] = n - 1 - ans[i];
            }
            reverse(ans.begin(), ans.end());
        }
        cout << abs(st - en) << " " << sum << "\n";
        for(int x : ans) cout << x + 1 << " ";
        cout << "\n";
        t--;
    }
    return 0;
}