
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uniqueNums;
        for(int num : nums){
            if(uniqueNums.find(num) != uniqueNums.end()){
                return true;
            }
            uniqueNums.insert(num);
        }
        return false;
    }
};