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

        vector<int> link[n+1];
        int parent[n+1] = {};
        int numchild[n+1] = {-1};
        
        int u , v;
        for(int i = 1; i <= n ; i++){
            cin >> u >> v;
            link[u].push_back(v);
            link[v].push_back(u);
        }

        vector<int> stk;
        stk.push_back(1);
        while(!stk.empty()){
            int curr = stk.back();
            stk.pop_back();

            if(link[curr].size() < 2){
                numchild[curr] = 0;
            }
            numchild[parent[curr]] += numchild[curr];

            for(auto x : link[curr]){
                if(x != parent[curr]){
                    parent[x] = curr;
                    stk.push_back(x);
                }
            }
        }
        for(int i = 1; i <= n; i++){
            cout << numchild[i] << " ";
        }
        cout  << "\n";
        
        t--;
    }
    return 0;
}