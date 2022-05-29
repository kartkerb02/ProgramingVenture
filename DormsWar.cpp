#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k;
    string s;
    cin >> t;
    while(t > 0){
        cin >> n >> s >> k;
        char spl[k];
        vector<int> pos;
        for(int i = 0; i < k; i++){
            cin >> spl[i];
        }
        int mem = 0;
        for(int i = 1; i < n; i++){
            if(find(spl,spl+k,s[i]) != spl+k){
                pos.push_back(i-mem);
                mem = i;
            }
        }
        //mem is the index of last spl character
        
        sort(pos.begin(), pos.end());
        // for(int i = 1; i < pos.size(); i++){
        //     pos[i] -= pos[i-1];
        // }
        int deletes = mem;
        int count = 0;
        int toll = pos.size();
        int  curr = 0;
        while(deletes > 0){
            if(deletes > pos[curr]*toll){
                deletes -= pos[curr]*toll;
                count += pos[curr];
                pos[curr] = 0;

                if(pos[curr] == 0 && curr < pos.size()-1){
                    curr++;
                    pos[curr]-= count;
                    toll-=1;
                }   
            }
            else{
                deletes -= toll;
                pos[curr]-=1;
                count++;
                if(pos[curr] == 0 && curr < pos.size()-1){
                    curr++;
                    pos[curr]-= count;
                    toll-=1;
                }   
            } 
        } 
        cout << count << "\n";
        t--;
    }
    return 0;
}