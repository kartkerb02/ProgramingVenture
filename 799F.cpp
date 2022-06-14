#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;   
    while(t){
        int n, temp;
        int freq[10]={};

        cin >> n;
        for(int i = 0; i < n; i++){cin >> temp; freq[temp%10]++;}
        // for(int i = 0; i < 10 ; i++){cout << freq[i] << " ";}
        // cout << "*\n";
        bool out = false;
        for(int i = 0; i < 10 && !out; i++){
            if(freq[i] > 0){
                freq[i]--;
                int sum2 = (13 - i)%10;
                for(int j = 0; j < 10 && !out; j++){
                    if(freq[j] > 0){
                        freq[j]--;
                        if(freq[(10 + sum2 - j)%10] > 0){
                            out = true;
                            //cout << sum2 << " " << j <<  "*";
                        }
                        freq[j]++;
                    }
                }
                freq[i]++;
            }
        }
        cout << (out? "yes" : "no") << "\n";
        
        t--;
    }
    return 0;
}