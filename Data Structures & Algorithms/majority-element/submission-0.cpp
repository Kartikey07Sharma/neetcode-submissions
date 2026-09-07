class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int cur ;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(count == 0)
            {
                cur = nums[i];
                count++;
            }
            else if(nums[i] == cur)
            {
                count++;
            }
            else count--;
        }
        count = 0;
        for(int x : nums)
        {
            if(x == cur)count++;
        }
        if(count > n/2)return cur;
        else return -1;
    }
};