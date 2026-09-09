class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxAns = 0;
        while(left < right)
        {
            int len = min(heights[left] , heights[right]);
            int wid = right - left;
            int vol = len * wid;
            maxAns = max(maxAns, vol);
            if(heights[left] > heights[right])
            {
                right--;
            }
            else {
                left++;
            }
        } 
        return maxAns;   
    }
};
