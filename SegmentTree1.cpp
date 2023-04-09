#include <bits/stdc++.h>
using namespace std;

class SegTree {
    vector<int> ST;
    vector<int> nums;
    int constructST(int l, int r, int ind){
        if(l == r) {
            ST[ind] = nums[l];
        }
        else{
            int m = l + (r-l)/2;
            ST[ind] = constructST(l, m, 2*ind + 1) + constructST(m+1, r, 2*ind + 2);
        }
        return ST[ind];
    }
    // ind is current index of the ST
    void updateUtil(int l, int r, int index, int diff, int ind){
        if(index < l || index > r) return ;
        ST[ind] += diff;
        if(l != r){
            int m = l + (r-l)/2;
            if(index <= m) updateUtil(l, m, index, diff, 2*ind + 1);
            else updateUtil(m+1, r, index, diff, 2*ind+2);
        }
    }
    int sumUtil(int l, int r, int left, int right, int ind){
        if(left <= l && r <= right) return ST[ind];
        if(r < left || l > right) return 0;
        int m = l + (r-l)/2;
        return sumUtil(l, m, left, right, 2*ind + 1) + sumUtil(m+1, r, left, right, 2*ind+2);
    }

public:
    SegTree(vector<int>& arr) {
        nums = arr;
        int n = nums.size();
        int ht = ceil(log2(n));
        int sz = pow(2, ht+1) - 1;
        
        ST.resize(sz);
        constructST(0, nums.size()-1, 0);
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        updateUtil(0, nums.size() - 1, index, diff, 0);
    }
    
    int sumRange(int left, int right) {
        return sumUtil(0, nums.size() - 1, left, right, 0);
    }
};

// hash version for frequency of a value in a given range;
class RangeFreqQuery{
public:

unordered_map<int,vector<int>> hash;

RangeFreqQuery(vector<int>& nums) 
{
    for(int i=0;i<nums.size();i++)
        hash[nums[i]].push_back(i);
}

int query(int left, int right, int val) 
{   
    auto l=lower_bound(hash[val].begin(),hash[val].end(),left);
    auto r=upper_bound(hash[val].begin(),hash[val].end(),right);
    
    return r-l;
}
};

int main(){
    vector<int> nums = {1,2,3,4,10,6,2};
    SegTree* st = new SegTree(nums);
    cout << st->sumRange(0, 3) << " ";
    st->update(2, 99);
    cout << st->sumRange(0, 6) << " ";
    return 0;
}

