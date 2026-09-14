class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size()-1;
        int mini = INT_MAX;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[low] <= nums[mid])
            {
                if(mini > nums[low])
                {
                    mini = nums[low];
                }
                low = mid+1;
            }
            else{
                if(mini > nums[mid+1])
                {
                    mini = nums[mid+1];
                }
                high = mid ;
            }
        }    
        return mini;
    }
};
