class Solution {
public:
    int countPartition(vector<int>& nums, int maxSum)
    {
        int partition = 1;
        long long partitionSum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(partitionSum + nums[i] <= maxSum)
            {
                partitionSum += nums[i];
            }
            else{
                partition++;
                partitionSum = nums[i];
            }
        }
        return partition;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        for(int i=0; i<nums.size(); i++)
        {
            low = max(low , nums[i]);
            high += nums[i];
        }    

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int partition = countPartition(nums, mid);
            if(partition > k)
            {
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};