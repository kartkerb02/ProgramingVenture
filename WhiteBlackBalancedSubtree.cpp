#include<bits/stdc++.h>
using namespace std;


class Node {
  public:

    int data;
    vector<Node*> children;
    int w = 0;
    int b = 0;
    Node(int val)
    {
        data = val;
        children = {};
        w = 0;
        b = 0;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n;
    string s;
    cin >> t;
    while(t > 0){
        cin >> n;
        vector<Node> Tree;

        for(int i = 0; i <= n; i++){
            Tree.push_back(Node(i));
        }
        int temp;
        for(int i = 2; i <= n; i ++){
            cin >> temp;
            Tree[temp].children.push_back(&Tree[i]);
        }
        cin >> s;

        // vector<Node> leaves;
        // for(int i = 1; i <= n; i++){
        //     if(Tree[i].children.size() == 0){
        //         leaves.push_back(Node(i));
        //     }
        // }
        vector<int> RecStack;
        RecStack.push_back(1);
        int curr;
        bool ready;
        while(!RecStack.empty()){
            curr = RecStack.back();
            ready = true;
            
            for(int i = 0; i < Tree[curr].children.size(); i++){
                if(Tree[curr].children[i]->w == 0 && Tree[curr].children[i]->b == 0){
                    RecStack.push_back(Tree[curr].children[i]->data);
                    ready = false;
                }
            }
            if(ready){
                Tree[curr].b = (s[curr-1] == 'W')? 0 : 1;
                Tree[curr].w = (s[curr-1] == 'W')? 1 : 0;
                for(int i = 0; i < Tree[curr].children.size(); i++){
                    Tree[curr].b += Tree[curr].children[i]->b;
                    Tree[curr].w += Tree[curr].children[i]->w;
                }
                RecStack.pop_back();
            }
        }
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(Tree[i].b == Tree[i].w){
                count++;
            }
            //cout << Tree[i].b << " " << Tree[i].w << "/";
        }
        cout << count << "\n";
        //cout <<  "#\n";
        t--;
    }
    return 0;
}

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int t, n;
//     string s;
//     cin >> t;
//     while(t > 0){
//         cin >> n;
//         int parent[n] = {};
//         vector<int> children[n+1];
//         for(int i = 1; i < n; i++){
//             cin >> parent[i];
//             children[parent[i]].push_back(i);
//         }
//         cin >> s;
//         int white[n+1];
//         int black[n+1];
        
    
//         t--;
//     }
//     return 0;
// }