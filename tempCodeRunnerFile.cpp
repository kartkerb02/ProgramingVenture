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
        string temp;

        vector<string> brd;
        for(int i = 0; i< n; i++){cin >> temp; brd.push_back(temp);}

        int tl = INT_MAX, br = INT_MIN, tr = INT_MIN, bl = INT_MAX;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j<= m; j++){
                if(brd[i-1][j-1] == 'B'){
                    tl = min(tl, i+j);
                    br = max(br, i+j);
                    tr = max(tr, j-i);
                    bl = min(bl, j-i);
                }
            }
        }

        //cout << tl << " " << br << " " << tr << " " << bl << "*\n";
        float d1 = (tl + br) / 2;
        float d2 = (tr + bl) / 2;
        
        float x = (d1 - d2) / 2;
        float y = (d1 + d2) / 2;

        cout << floor(x) << " " << floor(y) << "\n";
        t--;
    }
    return 0;
}