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
        int A[n+1] = {};
        for(int i = 1; i <= n; i++){cin >> A[i];}
        unordered_map<int, vector<int>> dict;

        for(int i = 1; i <= n; i++){
            dict[A[i]].push_back(i);
        }
        int master_max_value = 0, master_max = 0, l_master = -1, r_master = -1;
        // for (auto i : dict)
        // cout << i.first << "   " << i.second.size()
        //      << endl;
        for(auto x : dict){
            int curr = x.first;
            int l = x.second[0], r = x.second[0], strt = x.second[0];
            int max_so_far = 1;
            int curr_max = 1;
            for(int i = 1; i < x.second.size(); i++){
                if(curr_max + (1 - (x.second[i] - x.second[i-1] -1) > 1)){
                    curr_max = curr_max + 1 - (x.second[i] - x.second[i-1] -1);
                }
                else{
                    curr_max = 1;
                    strt = x.second[i];
                }
                if(curr_max > max_so_far){
                    max_so_far = curr_max;
                    r = x.second[i];
                    l = strt;
                }
            }
            //cout << curr << " " << max_so_far << " " << l << " " << r << "*\n";
            if(max_so_far > master_max_value){
                master_max_value = max_so_far;
                master_max = curr;
                l_master = l;
                r_master = r;
            }
        }
        cout << master_max << " " << l_master << " " << r_master << "\n";
        t--;
    }
    return 0;
}