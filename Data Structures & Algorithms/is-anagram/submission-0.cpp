class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())return false;

        int freq[256] = {0};
        for(int i=0; i < s.size(); i++)
        {
            freq[s[i]]++;
            freq[t[i]]--;    
        }

        for(int i : freq)
        {
            if(i != 0)return false;
        }
        return true;
    }
};
