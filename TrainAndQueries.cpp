#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n, k;
        cin >> n >> k;
        unordered_map<int, pair<int, int>> mp;
        int temp, a, b;
        for(int i = 1; i <= n; i++){
            cin >> temp;
            mp[temp].second = i;
            if(mp[temp].first == 0) mp[temp].first = i;
        }
        
        for(int i = 0; i < k; i++){
            cin >> a >> b;
            if(!mp[a].first || !mp[b].first || mp[a].first > mp[b].second){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }
        }

        t--;
    }
    return 0;
}