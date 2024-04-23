class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        //constroi hash table
        for(int i=0; i<n;i++){
            numMap[nums[i]] = i;
        }

        //find complement
        for(int i=0; i<n;i++){
            int complement = target - nums[i];
            if(numMap.count(complement) && numMap[complement] != i)
                return {i, numMap[complement]};
        }
        return {};
    }
};