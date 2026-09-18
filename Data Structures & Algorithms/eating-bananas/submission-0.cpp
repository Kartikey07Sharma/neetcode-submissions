class Solution {
public:

    int find(vector<int>& piles, int k)
    {
        int count = 0;
        for(int i=0; i<piles.size(); i++)
        {
            count += ceil((double)piles[i] / (double)k);
        }
        return count;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for(int i=0; i<piles.size(); i++)
        {
            high = max(high , piles[i]);
        }
        int ans;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int hours = find(piles, mid);
            if(hours <= h)
            {
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
