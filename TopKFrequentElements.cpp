// Link -> https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h> 
#include <vector>

// Driver function to sort the vector elements 
    // by second element of pairs 
    bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) { 
    return (a.second > b.second); 
    } 

class Solution {
public:
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        vector< pair <int,int> > uni;
        sort(nums.begin(), nums.end());
        int x = nums[0];
        uni.push_back(make_pair(x,0));
        for (int i=0; i<nums.size(); i++){
            if (nums[i] != x){
                x = nums[i];
                uni.push_back(make_pair(x,1));
            }
            else {
                uni[uni.size()-1].second++;
            }
        }
        sort(uni.begin(), uni.end(), sortbysec); 
    
        for (int i=0; i<k; i++){
        res.push_back(uni[i].first);  
        }
        
        return res;
    }
    
};