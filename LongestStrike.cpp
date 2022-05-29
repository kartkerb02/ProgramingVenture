#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n , k;
    cin >> t;
    while(t > 0){
        cin >> n >> k;
        int A[n];
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        sort(A, A+n);
        vector<pair<int, int>> freq;

        int count = 1;
        int prev = A[0];

        for(int i = 1; i < n; i++){
            if(A[i] == prev){
                count++;
            }
            else{
                freq.push_back(pair(A[i-1], count));
                count = 1;
                prev = A[i];
            }
        }
        freq.push_back(pair(prev, count));
        // for(auto x: freq){
        //     cout << x.first << " ";
        // }
        // cout << "#\n";
        int len = freq.size();
        int mx = -1, l = -1, r = -1, maxl, maxr;
        bool status = false;

        for(int i = 0; i < len; i++){
            if(freq[i].second >= k && !status){
                l = i;
                r = i;
                if(r-l > mx){
                    mx = r-l;
                    maxr = freq[r].first;
                    maxl = freq[l].first;
                }
                status = true;
            }
            else if(freq[i].second >= k && status){
                if(freq[i-1].first + 1 == freq[i].first){
                    r++;
                    if(r-l > mx){
                        mx = r-l;
                        maxr = freq[r].first;
                        maxl = freq[l].first;
                    }
                }
                else{
                    l = i;
                    r = i;
                }  
            } 
            else if(freq[i].second < k ){
                status = false;
            }
        }

        if(l == -1 && r == -1){
            cout << -1 << "\n";
        }
        else{
            cout << maxl << " " << maxr << "\n";
            //cout << mx << "\n";
        }
        t--;
    }


    return 0;
}