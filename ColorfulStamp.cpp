#include<bits/stdc++.h>
using namespace std;

bool chk(string str){
    int i = 0;
    int j = str.length();
    bool red = false;
    bool blue = false;
    for(int k = i; k< j; k++){
        if(str[k] == 'R') red = true;
        else if(str[k] == 'B') blue = true;
    }
    return red & blue || str == "";
}

void exe(){
    int n;
    cin >> n;
    
    string str;
    cin >> str;

    stringstream ss(str);
    string word;
    while(getline(ss,word,'W')){
        if(chk(word) == false){
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t >0){
        exe();
        t--;
    }
}