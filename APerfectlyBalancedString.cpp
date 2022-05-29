#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    string s;
    int l, mini, maxi;
    while(t > 0){
        cin >> s;
        
        string OUT = "YES";

        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }

        unordered_map<char,vector<int>> locations;
        for(int i = 0; i < s.size(); i++){
            locations[s[i]].push_back(i);
        }
        
        for(auto x: mp){
            for(int i = 0; i + 1< locations[x.first].size(); i++){
                if(locations[x.first][i+1] - locations[x.first][i] < mp.size()){
                    OUT = "NO";
                }
            }
        }
        cout << OUT << "\n";
        t--;
    }
    return 0;
}