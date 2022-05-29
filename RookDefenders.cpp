#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q, t, x, y, a, b;
    bool ret0, ret1;
    cin >> n >> q;
    ordered_set r, c;
    int row[n+1] = {};
    int col[n+1] = {};
    while(q > 0){
        cin >> t;
        if(t == 1){
            cin >> x >> y;
            row[x]++;
            col[y]++;
            r.insert(x);
            c.insert(y);
        }
        else if(t == 2){
            cin >> x >> y;
            row[x]--;
            col[y]--;
            if(row[x] == 0){
                r.erase(x);
            }
            if(col[y] == 0){
                c.erase(y);
            }
        }
        else if(t == 3){
            cin >> x >> y >> a >> b;
            bool ret0 = ((r.order_of_key(a+1) - r.order_of_key(x)) == (a-x+1));
            bool ret1 = ((c.order_of_key(b+1) - c.order_of_key(y)) == (b-y+1));
            cout << ((ret1 || ret0) ? "yes" : "no") << "\n";
        }
        q--;
        // for(auto x: row){
        //     cout << x << " ";
        // }
        // cout << "#\n";
        // for(auto x: col){
        //     cout << x << " ";
        // }
        // cout << "#\n";
    }
}