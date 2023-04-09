#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//Using stringstream
vector<string> ParseString(string s, char del){

    vector<string> words;
    stringstream sstream(s);
    string token;
    while (std::getline(sstream, token, del)){
        words.push_back(token);
    }
    return words;
}
//iterating over string
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

//subarray with max sum
int MaxSumSubstring(int* Arr, int n){
    int curr_max = Arr[0];
    int max_so_far = Arr[0];
    for(int i = 1; i < n; i++){
        curr_max = max(curr_max + Arr[i], Arr[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

//Knap sack unlimited weights and order matters
vector<vector<int>> combinationSum(vector<int>& candidates, int target){ 
    int num = candidates.size();
    vector<vector<int>> dp[target + 1];
    
    for(int i = 1; i <= target; i++){
        for(auto c : candidates){
            if(c == i){
                dp[i].push_back({c});
            }
            else if(c < i){
                vector<vector<int>> temp = dp[i - c];
                for(int j = 0; j < temp.size(); j++){
                    temp[j].push_back(c);
                }
                dp[i].insert(dp[i].end(), temp.begin(), temp.end());
            }
            
        }
    }
    return dp[target];
}

//Knap sack unlimited weights and order doesn't matter
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int num = candidates.size();
    vector<vector<int>> dp[target + 1][num];
    
    for(int k = 0; k < num; k++){
        for(int i = 1; i <= target; i++){
            for(int l = 0; l <= k; l++){
                int c = candidates[l];
                if(c == i){
                    dp[i][k].push_back({c});
                }
                else if(c < i){
                    vector<vector<int>> temp = dp[i - c][l];
                    for(int j = 0; j < temp.size(); j++){
                        temp[j].push_back(c);
                    }
                    dp[i][k].insert(dp[i][k].end(), temp.begin(), temp.end());
                }

            }
        }
    }
    return dp[target][num - 1];
}

//binary search and insert
int searchInsert(vector<int>& nums, int target){
    int l = 0;
    int r = n - 1;
    int m;
    while(l <= r){
        m = l + (r-l)/2;
        if(nums[m] == target){return m;}
        else if(nums[m] < target){l = m + 1;}
        else{r = m - 1;}
    }
    return l;
}

int C(int n, int r){
    int N = 1e9 + 7;
    long long ret = 1;
    for(int i = 1; i <= r; i++){
        ret = ((ret*(n-i+1))/i)%N;
    }
    return (int) ret;
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

