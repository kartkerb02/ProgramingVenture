#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n, m;
        cin >> n >> m;
        string s(m, 'B');
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            temp--;
            temp = min(temp, m - 1 - temp);
            if(s[temp] == 'A' && s[m - 1 - temp] == 'B'){
                s[m - 1 - temp] = 'A';
            }
            else if(s[temp] == 'B') s[temp] = 'A';
        }
        cout << s << "\n";
        t--;
    }
    return 0;
}