#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t>0){
        int n;
        cin >> n;
        if(n==1){
            int x;
            cin >> x;
            cout << 1 << "\n" << 1 << "\n" << x << "\n" << "\n"; 
        }
        else{
            int P[n+1];
            for (int i = 1; i <= n; i++) {cin >> P[i];} //P[i] is parent of i

            unordered_map<int, int> parents;
            for (int i = 1; i <= n; i++) {parents[P[i]]++;}//parents[i] tells number of children of i

            vector<int> leaves;
            for (int i = 1; i <= n; i++){
                
                if(parents[i] == 0){
                    leaves.push_back(i);// i in leaves => i is a leaf
                    //cout << i << "\n";
                }
            }
            
            cout << leaves.size() << "\n";

            int curr;
            for (vector<int>::iterator itr = leaves.begin(); itr != leaves.end(); ++itr){
                curr = *itr;
                vector<int> out;
                out.push_back(curr);
                curr = P[curr];
                while(parents[curr] != 0){
                    out.push_back(curr);
                    parents[curr] = 0;
                    curr = P[curr];
                }

                int len = out.size();
                cout << len << "\n";
                for(int i = len-1; i >= 0; i--){
                    cout << out[i] << " ";
                }
                cout << "\n" ;
            }
        }
        t--;
        cout << "\n" ;
    }
    return 0;
}