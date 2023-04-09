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
        string s; 
        cin >> s;
        string to = "";
        for(int i = n-1; i >= 0; i--){
            if(s[i] != '0') to += (char)('a' + s[i] - '1');
            else{
                to += (char)('a' + stoi(s.substr(i-2, 2)) - 1);
                i -= 2;
            }
        }
        reverse(to.begin(), to.end());
        cout << to << "\n";
        t--;
    }
    return 0;
}