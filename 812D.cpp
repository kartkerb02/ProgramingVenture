#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void give(int x){
    x++;
    printf("! %d\n", x);
    fflush(stdout);
}


int query(int x, int y){
    x++;
    y++;
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int ans;
    cin >> ans; 
    return ans;
}

// void solve2(vector<int>& a, int ind, int tg){
//     for(int i = ind; i < a.size(); i++){
//         int res = query(a[i], tg);
//         if(res == 1){
//             give(a[i]); return;
//         }
//     }
// }

// void solve(vector<int>& a, vector<int>& b){
//     int p = 0, q = 0;
//     int n = a.size(), m = b.size();

//     vector<int> tmp;
//     while(p < n && q < m){
//         int res = query(p, q);
//         if(res == 2){
//             p++;
//             if(tmp.size()) tmp.clear();
//         }
//         else if(res == 1){
//             q++;
//             if(tmp.size()) tmp.clear();
//         }
//         else if(res == 0){
//             tmp.push_back(q);
//             q++;
//         }
//         if(p == n && tmp.size() == 0){
//             give(q);
//             return;
//         }
//         else if(q == m && tmp.size() == 0){
//             give(p);
//             return;
//         }
//         else if(p == n && tmp.size() != 0){
//             solve2(b, q+1, tmp[0]);
//         }
//         else if(q == m && tmp.size() != 0){
//             solve2(a, p+1, tmp[0]);
//         }
//     }
    
// }
void solve(int r){
    int p = 0;
    int n = (1 << (r-1));

    int q = n;
    int m = 1 << r;

    while(p < n && q < m){
        int res = query(p, q);
        if(res == 2){
            p++;
        }
        else if(res == 1){
            q++;
        }
        else if(res == 0){
            p++;
            q++;
        }
        else cout << "ERROR" << "\n";
    }
    if(p == n && q < m) give(q);
    if(q == m && p < n) give(p);
}

int main(){

    int t;
    cin >> t;   
    while(t){
        int n;
        cin >> n;
        
        solve(n);
        t--;
    }
    return 0;
}