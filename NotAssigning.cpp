#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;   
    while(t){
        int n;
        cin >> n;

        vector<pair<int, int>> link[n+1]; // link with , edge no

        int edgevalue[n-1];
        
        int u , v;
        for(int i = 0; i < n - 1; i++){
            cin >> u >> v;
            link[u].push_back(pair(v, i));
            link[v].push_back(pair(u, i));
            
        }
        bool go = true;
        
        
        vector<int> ends;
        for(int i = 1; i <= n && go; i++){
            if(link[i].size() > 2){
                
                go = false;
            }
            if(link[i].size() == 1){
                ends.push_back(i);
            }
        }
        if(go){
            int curr = ends[0];
            //cout << curr << "#";
            edgevalue[link[curr][0].second] = 2;
            int last = 2;
            int prev = curr;
            curr = link[curr][0].first;
            for(int i = 0; i < n -1; i++){
                if(link[curr][0].first != prev){
                    edgevalue[link[curr][0].second] = 6 / last;
                    last = 6 / last;
                    prev = curr;
                    curr = link[curr][0].first;
                }
                else if(link[curr].size() > 1){
                    edgevalue[link[curr][1].second] = 6 / last;
                    last = 6 / last;
                    prev = curr;
                    curr = link[curr][1].first;
                }
            }
            for(auto x : edgevalue){
                cout << x << " ";
            }
            cout << "\n";
        }
        else{
            cout << -1 << "\n";
        }
        t--;
    }
    return 0;
}