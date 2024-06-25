class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // exactly one solution with no duplicate elements,
        // can get the answer by finding the targets complement in given 
        // array.
        // ex: complement = target - nums[i] 

        unordered_map<int, int> umap; 
        int n = nums.size(); 

        for (int i = 0; i < n; i++) 
        {
            int complement = target - nums[i];

            // check if the complement exists and return the pair if it does
            if (umap.count(complement)) 
            {
                return {umap[complement], i};
            }

            // add the current number onto the list for future reference
            umap[nums[i]] = i; 
        }

        // return an empty pair if you do not find anything
        return {};
    }
};
