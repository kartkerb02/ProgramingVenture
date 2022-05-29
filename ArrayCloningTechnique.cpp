
#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    int l, temp, mx;
    while (n > 0){
        cin >> l;
        unordered_map<long long int, int> ump;
        mx = 0;
        for (int i =0; i< l; i++){
            cin >> temp;
            ump[temp]++;
            mx = max(mx, ump[temp]);
        }
        float c = float(l)/mx;
        temp = ceil(log2(c)) + l - mx;
        cout <<  temp << "\n";
        n--;
    }
    return 0;
}
