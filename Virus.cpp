#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<int>& A, int m){
    sort(A.begin(), A.end());
    vector<int> sizes;
    for(int i = 0; i < m-1; i++){
        if(A[i+1]-A[i]-1 > 0)sizes.push_back(A[i+1]-A[i]-1);
    }
    sizes.push_back(n-A.back() + A[0]-1);
    sort(sizes.begin(), sizes.end(), greater<int>());
    int ans = 0;
    // for(int x : sizes) cout << x << "_";
    for(int i = 0; i < sizes.size(); i++){
        if(sizes[i] - (4*i+1) == 0){
            ans++;
        }
        if(sizes[i] - (4*i+1) > 0){
            ans += sizes[i] - (4*i+1);
        }
        else break;
    }
    return n - ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n, m;
        cin >> n >> m;
        vector<int> A(m);
        for(int i = 0; i < m; i++) cin >> A[i];
        cout << solve(n, A, m) << "\n";
        t--;
    }
    return 0;
}