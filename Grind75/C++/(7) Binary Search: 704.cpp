class Solution {
public:
    int recursiveSearch(vector<int> nums, int low, int high, int target)
    {
        if (low <= high) 
        {
            // calculate the middle value to determine where the target lies
            int middle = low + ((high - low) / 2); 
            
            // return the middle value if its equal to the target value
            if (nums[middle] == target)
            {
                return middle; 
            }

            // search the right side if the target is greater than the middle
            if (nums[middle] < target)
            {
                return recursiveSearch(nums, middle + 1, high, target);
            }

            // search the left side if the target is less than the middle
            return recursiveSearch(nums, low, middle - 1, target);
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        // start time: 2:53pm
        // end time: 3:22pm

        // problem breakdown: 
        // binary search (O(log(n))) where the target may be found within the
        // array

        // possible solution: 
        // breakdown the problem into halves and find the range that better 
        // suits the target integer
        
        // return the helper method that recursively iterates through the array
        return recursiveSearch(nums, 0, nums.size() - 1, target);
    }
};
