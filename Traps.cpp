#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool sortbyfirstdec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.first > b.first);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t > 0){
        int n, k, sum = 0;
        cin >> n >> k;

        int A[n+1] = {};
        int save[n+1] = {};
        for(int i = 1; i <= n; i++){
            cin >> A[i];
            sum += A[i];
            save[i] = A[i] - n + i; 
        }
        sort(save + 1, save + n + 1, greater<int>());
        // for(int i = 1; i <= n; i++){
        //     cout << save[i] << " ";
        // }
        // cout << "#\n";
        for(int i = 1; i <= k && save[i] >= 0 ; i++){
            sum -= (save[i] + i - 1);
        }
        cout << sum << "\n";
        t--;
    }
    return 0;
}