#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    int t;
    cin >> t;   
    while(t){
        int n1, n2, k;
        cin >> n1 >> n2 >> k;

        string s1 , s2;
        cin >> s1 >> s2;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        string out = "";
        int i = 0, j = 0, cnt1 = 0, cnt2 = 0;
        while(i < n1 && j < n2){
            if(cnt1 == k){
                cnt1 = 0;

                out.push_back(s2[j]);
                j+=1;
                cnt2++;
            }
            else if(cnt2 == k){
                cnt2 = 0;

                out.push_back(s1[i]);
                i+=1;
                cnt1++;
            }
            else if(s1[i] > s2[j]){
                out.push_back(s2[j]);
                j+=1;
                cnt2++;
                cnt1 = 0;
            }
            else{
                out.push_back(s1[i]);
                i+=1;
                cnt1++;
                cnt2 = 0;
            }
        }

        cout << out << "\n";
        //if(out == "abcd"){cout << k << "$" << cnt1 << "$" << cnt2<< "$" << n1 <<"$" << n2<< "$" << i << "%" << j;}
        t--;
    }
    return 0;
}