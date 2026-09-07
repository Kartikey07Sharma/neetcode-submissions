class Solution {
   public:
    
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        int count = 0;
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            if (prefix[i] == k) count++;
            int need = prefix[i] - k;
            if (mp.find(need) != mp.end()) {
                count += mp[need];
            }
            mp[prefix[i]]++;
        }
        return count;
    }
};