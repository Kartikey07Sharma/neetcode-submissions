class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp; //<value , index>
        for(int i=0; i<nums.size(); i++)
        {
            auto it = mp.find(nums[i]);
            if(it != mp.end())
            {
                int value = it->first;
                int index = it->second;
                if(abs(i - index) <= k)return true; 
                else{
                    mp[nums[i]] = i;
                }
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};