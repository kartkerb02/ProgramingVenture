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
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.begin() + 4);
        int mx1 = a[3], mx2 = a[2],  mn1 = a[0], mn2 = a[1];
        for(int i = 4; i < n; i++){
            if(a[i] > mx1){
                mx2 = mx1;
                mx1 = a[i];
            }
            else if(a[i] > mx2){
                mx2 = a[i];
            }
            if(a[i] < mn1){
                mn2 = mn1;
                mn1 = a[i];
            }
            else if(a[i] < mn2){
                mn2 = a[i];
            }
        }
        cout << mx1 + mx2 - mn1 - mn2 << "\n";
        t--;
    }
    return 0;
}