class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(char ch : s)
        {
            if(isalnum(ch))
            {
                char x = tolower(ch);
                str.push_back(x);
            }
        }
        int low = 0;
        int high = str.size()-1;
        while(low < high)
        {
            if(str[low] != str[high])return false;
            low++;
            high--;
        }
        return true;
    }
};
