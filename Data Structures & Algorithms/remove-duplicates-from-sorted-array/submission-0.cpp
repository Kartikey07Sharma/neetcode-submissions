class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0;
        for(int j=i+1; j<nums.size(); j++)
        {
            if(nums[j] != nums[i])
            {
                swap(nums[j] , nums[i+1]);
                i++;
            }
        }
        return i + 1;
    }
};