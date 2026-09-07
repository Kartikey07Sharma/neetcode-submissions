class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 1;
        int n = nums.size();
        if(n == 0)return 0;

        unordered_set<int> st;
        for(int x : nums)
        {
            st.insert(x);
        }
        for(int it : st)
        {
            int count = 0;
            if(st.find(it-1) == st.end())
            {
                int cur = it;
                count = 1;
                while(st.find(cur+1) != st.end())
                {
                    cur  = cur+1;
                    count++;
                }
            }
            longest = max(longest, count);
        }
        return longest;
    }
};
