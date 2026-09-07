class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int first = 0, second = 0;
        int countFirst = 0, countSecond = 0;

        for(int num : nums)
        {
            if(num == first)
            {
                countFirst++;
            }
            else if(num == second)
            {
                countSecond++;
            }
            else if(countFirst == 0)
            {
                first = num;
                countFirst = 1;
            }
            else if(countSecond == 0)
            {
                second = num;
                countSecond = 1;
            }
            else
            {
                countFirst--;
                countSecond--;
            }
        }

        countFirst = 0;
        countSecond = 0;

        for(int num : nums)
        {
            if(num == first)
                countFirst++;
            else if(num == second)
                countSecond++;
        }

        vector<int> ans;
        int n = nums.size();

        if(countFirst > n / 3)
            ans.push_back(first);

        if(countSecond > n / 3)
            ans.push_back(second);

        return ans;
    }
};