class Solution {
   public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(string s : strs)
        {
            string k = s;
            sort(k.begin(), k.end());
            mp[k].push_back(s);
        }
        for(auto x : mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
