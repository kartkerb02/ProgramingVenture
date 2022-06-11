#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    int id[n+1];
    unordered_set<int> groups[n+1];
    for(int i = 0; i <= n; i++){
        id[i] = i;
        groups[i].insert(i);
    }
    int x , y, mx = 1, extras = 1;
    for(int i = 0; i < d; i++){
        cin >> x >> y;
        if(id[x] == id[y]){
            extras++;
        }
        else{
            int to_be_removed = id[y];
            for(auto elem : groups[id[y]]){
                id[elem] = id[x];
                groups[id[x]].insert(elem);
            }
            groups[to_be_removed].clear();
            //groups[id[x]].insert(groups[id[y]].begin(),groups[id[y]].end());
            int sz = groups[id[x]].size();
            mx = max(mx, sz);
        }
        // for(int i = 1; i <= n; i++){
        //     cout << groups[i].size() << " ";
        // }
        // cout << "\n";
        if(extras == 1){
            cout << mx - 1 << "\n";
        }
        else{
            int sizes[n+1];
            for(int i = 1; i <= n; i++){
                sizes[i] = groups[i].size();
            }
            sort(sizes + 1, sizes + n + 1, greater<int>());
            int out = 0;
            for(int i = 1; i <= extras; i++){
                out += sizes[i];
            } 
            cout << out - 1<< "\n";
        }

    }
    return 0;
}