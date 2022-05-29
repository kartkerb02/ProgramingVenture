#include<bits/stdc++.h>
using namespace std;

int N = 2e5;
unordered_set<struct Quad> dp[N];

struct Quad{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0; 
    bool out = false;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t > 0){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        string s;
        cin >> s;

        int n = s.size();
        s.push_back('x');
        
        for(int i = 0; i < n; i++){

        }
        
        t--;
    }
}