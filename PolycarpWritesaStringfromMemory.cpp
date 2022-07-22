#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        string s;
        cin >> s;

        vector<char> v(3, '#');
        int cnt = 1;
        for(char x : s){
            int i = 0;
            while(i < 3){
                if(v[i] == '#'){
                    v[i] = x;
                    break;
                }
                if(v[i] == x){
                    break;
                }
                i++;
            }
            if(i == 3){
                cnt++;
                v[0] = x;
                v[1] = '#';
                v[2] = '#';
            }
        }
        cout << cnt << "\n";
        t--;
    }
    return 0;
}