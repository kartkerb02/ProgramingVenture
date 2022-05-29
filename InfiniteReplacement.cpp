#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;
 
    string s, t;
    for(int  i = 0; i < m; i++){
        cin >> s >> t;
        int cnt = count(t.begin(), t.end(), 'a');
 
        long long int out;
        if(cnt == 0){
            out = pow(2, s.size());
        }
        else if(cnt == 1){
            if(t.size() == 1){
                out = 1;
            }
            else{
                out = -1;
            }
        }
    
        else{
            out = -1;
        }
        cout << out << "\n";
    }
}