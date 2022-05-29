#include<bits/stdc++.h>
using namespace std;

void solve(string s){
    unordered_map<char, int> mp;

    int deletes = 0;
    int done = 0;
    for(int i = 0; i < s.size(); i++){
        if(mp[s[i]] > done){
            deletes += i - done - 1;
            done = i + 1;
        }
        else{
            mp[s[i]] = i + 1;
        }
        //cout << deletes << "," << done << " ";
    }
    deletes += s.size() - done;
    cout << deletes << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    string s;
    while(t > 0){
        cin >> s;
        solve(s);
        t--;
    }
}