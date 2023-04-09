#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mn;
int n;
void solve(vector<int>& cost, vector<int>& time, int x, int c, int t){
    if(x < 0 || t < 0) return ;
    mn = min(mn, c);
    solve(cost, time, x-1, c-cost[x], t-time[x]-1);
    solve(cost, time, x-1, c, t);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> cost(n), time(n);
    for(int i = 0; i < n; i++) cin >> cost[i];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> time[i];
    int c = 0;
    for(int i = 0; i < n; i++) c += cost[i];
    int t = 0;
    for(int i = 0; i < n; i++) t += time[i];
    mn = n;
    // vector<bool> init(n, 1);
    solve(cost, time, n-1, t, c);
    cout << mn << "\n";

    return 0;
}


// // Online C++ compiler to run C++ program online
// #include <bits/stdc++.h>
// using namespace std;

// int main(){

//     int n;
//     cin>> n;
//     vector<int> cost;
//     for(int i=0;i<n;i++){
//         int x;
//         cin>>x;
//         cost.push_back(x);
//     }
//     int n2;
//     cin >> n2;
//     vector<int> time;
//     for(int i=0;i<n;i++){
//         int x;
//         cin >> x;
//         time.push_back(x);
//     }
//     priority_queue<pair<int,int>> pq;
//     priority_queue<pair<int,int>> pq2;
//     for(int i=0;i<n;i++){
//         double x ;
//         double y;
//         x = time[i]/cost[i];
//         y = cost[i];
//         pq.push({x,i});
//         pq2.push({y,i});

//     }
//     vector<int> vis(n,0);
//     int t =0;
//     int c;
//     while(!pq2.empty()&&!pq.empty()){
//         if(t==0){
//             pair<int,int> p = pq.top();
//             if(vis[p.second]==1){pq.pop();continue;}
//             t = time[p.second];
//             vis[p.second]=1;
//             c = c + cost[p.second];
//             while(t>0 && !pq2.empty()){
//                 pair<int,int> p2 = pq2.top();
//                 if(vis[p2.second]==1){continue;}
//                 t--;
//                 pq2.pop();
//                 vis[p2.second]=1;

//             }

//         }

//     }
//     cout<< c;
//     return 0;
// }