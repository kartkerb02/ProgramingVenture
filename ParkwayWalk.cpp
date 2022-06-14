#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n , m;
        cin >> n >> m;
        int a[n+1];
        for(int i = 1; i <= n; i++){cin >> a[i];}

        int req = 0;
        for(int i = 1; i<= n; i++){
            m -= a[i];
            if(m <= 0){
                req -= m;
                m = 0;
            }
        }
        cout << req << "\n";
        t--;
    }
    return 0;
}