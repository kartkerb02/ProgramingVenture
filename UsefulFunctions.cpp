#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> ParseString(string s, char del){
    vector<string> words;
    stringstream sstream(s);
    string token;
    while (std::getline(sstream, token, del)){
        words.push_back(token);
    }
    return words;
}
vector<string> ParseString2(string s, char del){
    vector<string> words;
    string token = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] != del){
            token += s[i]; 
        }
        else if(token.size() > 0){
            words.push_back(token);
            token = "";
        }
    }
    if(token.size() > 0){
        words.push_back(token);
        token = "";
    }

    return words;
}

int MaxSumSubstring(int* Arr, int n){
    int curr_max = Arr[0];
    int max_so_far = Arr[0];
    for(int i = 1; i < n; i++){
        curr_max = max(curr_max + Arr[i], Arr[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main(){
    vector<string> vec = ParseString2("*****", '*');
    cout << vec.size() << "\n";
    for(auto x : vec){
        cout << x << "\n";
    }    
    //cout << "\n";
    return 0;
}