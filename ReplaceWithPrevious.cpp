#include<bits/stdc++.h>
using namespace std;
inline int order(char c){return int(c) - 96;}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n , k;
    string s;
    cin >> t;

    for (int i = 0; i < t; i++){
        cin >> n >> k;
        cin >> s;

        int top = 1;
        int rangel = 0;
        int ranger = 0;
        int curr = 0;
        while(k > 0 && curr < n){
            if(order(s[curr]) > top){
                if(order(s[curr]) - top <= k){
                    k -= order(s[curr]) - top;
                    top = order(s[curr]);
                }
                else{
                    ranger = order(s[curr]);
                    rangel = ranger - k;
                    k = 0;
                }
            }
            curr += 1;
        }
        for(int l = 0; l < n; l++){
            if(order(s[l]) <= top){
                s[l] = 'a';
            }
            else if(order(s[l]) <= ranger && order(s[l]) >= rangel){
                s[l] = char(rangel + 96);
            }
        }
        cout << s << "\n";
    }
   
    return 0;
}