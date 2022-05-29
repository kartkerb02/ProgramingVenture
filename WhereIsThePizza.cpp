#include<bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, temp, c;
    cin >> t;
    
    while(t > 0){
        cin >> n;
        unordered_set<int> rem;
        for(int i = 1; i <= n; i++){
            rem.insert(i);
        }
        int A1[n+1];
        int A2[n+1];
        int B1[n+1];
        int B2[n+1];
        int D[n+1];
        for(int i = 1; i <= n; i++){
            cin >> temp;
            A1[i] = temp;
            A2[temp] = i;
        }
        for(int i = 1; i <= n; i++){
            cin >> temp;
            B1[i] = temp;
            B2[temp] = i;
        }
        for(int i = 1; i <= n; i++){
            cin >> temp;
            D[i] = temp;
            if(temp != 0){
                c = i;
                rem.erase(temp);
                while(rem.find(A1[c]) != rem.end() || rem.find(B1[c]) != rem.end()){
                    //cout << c << " ";
                    if(rem.find(A1[c]) == rem.end()){
                        rem.erase(B1[c]);
                        c= A2[B1[c]];
                    }
                    else{
                        rem.erase(A1[c]);
                        c= B2[A1[c]];
                    }
                }
            }
        }
        // unordered_set<int> :: iterator itr;
        // for (itr = rem.begin(); itr != rem.end(); itr++){
        //     cout << (*itr) << " ";
        // }
        // cout << "\n";
        int count = 0;
        int islandsz = 0;
        while(!rem.empty()){
            //cout << count;
            temp = *rem.begin();
            c = A2[temp];
            rem.erase(temp);
            //cout << temp << "#";
            islandsz = 1;
            while(rem.find(A1[c]) != rem.end() || rem.find(B1[c]) != rem.end()){
                islandsz++;
                if(rem.find(A1[c]) == rem.end()){
                    rem.erase(B1[c]);
                    c= A2[B1[c]];
                }
                else{
                    rem.erase(A1[c]);
                    c= B2[A1[c]];
                }
            }
            if(islandsz > 1){count++;}
        }
        long int out = 1;
        for(int i = 0; i < count; i++){
            out = (out*2) % N;
        }
        cout << out << "\n";
        t--;
    }
}