class Solution {
   public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxFreq = 0;
        int maxlen = 0;
        int r = 0;
        vector<int> freq(26, 0);
        while (r < s.size()) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            if (((r - l + 1) - maxFreq) > k) {
                freq[s[l] - 'A']--;

                l++;
            }
            if (((r - l + 1) - maxFreq) <= k) {
                maxlen = max(maxlen, (r - l + 1));
            }
            r++;
        }
        return maxlen;
    }
};
