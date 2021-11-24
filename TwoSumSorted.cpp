https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int previous = -1001;
        for (int i=0; i<numbers.size(); i++){
            if (previous == numbers[i]) continue;
            for (int j=numbers.size()-1; j>i; j--){
                if (numbers[i] + numbers[j] == target) {
                    res.push_back(i+1);
                    res.push_back(j+1);
                    return res;
                }
                else if (numbers[i] + numbers[j] < target) break;        

            }
            previous = i;
        }
        return res;
    }
};
