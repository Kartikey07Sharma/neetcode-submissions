class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> mp;
       for(int i=0; i<nums.size(); i++)
       {
        int need = target - nums[i];
        if(mp.find(need) != mp.end())
        {
            return {min(i, mp[need]) , max(i, mp[need])};
        }
        mp[nums[i]] = i;
       }
       return {};
    } 
};
