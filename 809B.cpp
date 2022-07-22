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
        int c[n];
        for(int i = 0; i < n; i++) {cin >> c[i]; c[i]--;}
        
        vector<int> v1[n], v2[n], v3[n];
        for(int i = 0; i < n; i++){
            if(v1[c[i]].size() == 0) v1[c[i]].push_back(i);
            else if((v1[c[i]].back() - i)&1){
                v1[c[i]].push_back(i);
            }
            if(v2[c[i]].size() == 0) v2[c[i]].push_back(i);
            else if((v2[c[i]].back() - i)&1){
                v2[c[i]].push_back(i);
            }
            if(v3[c[i]].size() == 0) v3[c[i]].push_back(i);
            else if((v3[c[i]].back() - i)&1){
                v3[c[i]].push_back(i);
            }
        }
        for(int i = 0; i < n; i++){
            cout << max(max(v1[i].size(), v2[i].size()), v3[i].size()) << " ";
        }
        cout << "\n";
        t--;
    }
    return 0;
}