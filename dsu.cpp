#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> pr;
vector<int> rank;
int find(int v){
    if(pr[v] == -1) return v;
    return pr[v] = find(pr[v]);
}

void union_op(int v, int w){
    int x = find(v);
    int y = find(w);

    if(rank[x] < rank[y]){
        pr[x] = y;
    }
    else if(rank[y] < rank[x]){
        pr[y] = x;
    }
    else{
        pr[x] = y;
        rank[y]++;
    }
}

bool iscyclic(vector<pair<int, int>> edges){
    for(auto e : edges){
        int x = find(e.first);
        int y = find(e.second);

        if(x == y) return true;
        union_op(e.first, e.second);
    }
    return false;
}
int main(){
    int N = 11;
    vector<pair<int, int>> edges = {{1,2}, {0,1}, {3,4}, {4,10}, {4, 2}, {0, 10}};
    pr.resize(N, -1);
    rank.resize(N, 0);

    
    cout << iscyclic(edges);
    return 0;
}