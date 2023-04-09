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
        vector<int> a(n);
        vector<bool> b(n, 0);
        bool allow = 1;

        for(int i = n-1; i >= 0; i--){
            if(!b[i]){
                int m = ceil(sqrt(i));
                while((m+1)*(m+1) <= 2*i) m++;
                int d = m*m - i;
                a[d] = i;
                a[i] = d;
                b[d] = 1;
                b[i] = 1;
            }
        }
        for(int i = 0; i < n; i++){
            if (ceil((double)sqrt(a[i] + i)) != floor((double)sqrt(a[i] + i))) allow = 0;
        }
        if(allow){
            for(int i = 0; i < n; i++) cout << a[i] << " ";
            cout << "\n";
        }
        else cout << -1 << "\n";
        t--;
    }
    return 0;
}