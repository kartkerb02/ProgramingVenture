#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxprofit(int n, vector<int>& prof, vector<int>& ded){
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&ded](int x, int y){
        return ded[x] < ded[y];
    });

    priority_queue<int> pq;

    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        int sa;
        if(i) sa = ded[ind[i]] - ded[ind[i-1]];
        else sa = ded[ind[i]];

        pq.push(prof[ind[i]]);

        while(!pq.empty() && sa > 0){
            ans += pq.top();
            pq.pop();
            sa--;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> pr = {20, 50, 100, 10, 5};
    vector<int> ded = {1, 2, 3, 1, 5};
    cout << maxprofit(5, pr, ded);
    return 0;
}