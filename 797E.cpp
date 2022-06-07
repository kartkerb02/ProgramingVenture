#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n, k;
        cin >> n >> k;
        long long int remfreq[k] = {};

        long long temp, sum = 0;
        for(int i = 0; i < n; i++){
            cin >> temp;
            sum += temp/k;
            remfreq[temp%k]++;
        }


        long long int i = 1, j = k-1;
        while(j > i && i + j >= k){
            long long int remove = min(remfreq[i], remfreq[j]);
            sum += remove;
            remfreq[i] -= remove;
            remfreq[j] -= remove;

            if(remfreq[j] == 0){
                j--;
            }
            if(remfreq[i] == 0 || j+i < k){
                i++;
            }
            //cout << i << '$' << j << '*' << sum << "*";
        }
        if(j == i && i + j >= k){
            sum += remfreq[i]/2;
            remfreq[i] -= 2*(remfreq[i]/2);
        }
        cout << sum << "\n";
        t--;
    }
    return 0;
}